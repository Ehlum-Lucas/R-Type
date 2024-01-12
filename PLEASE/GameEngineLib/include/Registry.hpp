#ifndef REGISTRY_HPP_
    #define REGISTRY_HPP_

    #include <typeindex>
    #include <functional>
    #include "SparseArray.hpp"
    #include "Entity.hpp"
    #include "Components.hpp"
    #include <unordered_map>
    #include <any>
    #include "parsing.hpp"
    #include <sstream>

    #define M_PI       3.14159265358979323846

    class Registry {
        public:

            Registry(std::shared_ptr<sf::RenderWindow> window, sf::Event &event) {
                _window = window;
                _event = event;
            }
            template <class Component>
            SparseArray<Component>& register_component() {
                std::type_index type = typeid(Component);
                if (_components_arrays.find(type) == _components_arrays.end()) {
                    _components_arrays[type] = SparseArray<Component>();
                }
                return std::any_cast<SparseArray<Component>&>(_components_arrays[type]);
            }

            template <class Component>
            SparseArray<Component>& get_components() {
                std::type_index type = typeid(Component);
                if (_components_arrays.find(type) == _components_arrays.end()) {
                    _components_arrays[type] = SparseArray<Component>();
                }
                return std::any_cast<SparseArray<Component>&>(_components_arrays[type]);
            }

            template <class Component>
            SparseArray<Component> const & get_components() const {
                std::type_index type = typeid(Component);
                if (_components_arrays.find(type) == _components_arrays.end()) {
                    _components_arrays.emplace(type, SparseArray<Component>());
                }
                return std::any_cast<SparseArray<Component> const &>(_components_arrays.at(type));
            }

            Entity create_entity() {
                entities.emplace_back();
                return entities.back();
            }

            void delete_entity_by_id(size_t id) {
                for (auto it = entities.begin(); it != entities.end(); ++it) {
                    if (it->get_id() == id) {
                        delete_components_by_entity_id<Position>(id);
                        delete_components_by_entity_id<Velocity>(id);
                        delete_components_by_entity_id<Drawable>(id);
                        delete_components_by_entity_id<CircleShape>(id);
                        delete_components_by_entity_id<RectangleShape>(id);
                        delete_components_by_entity_id<Color>(id);
                        delete_components_by_entity_id<Gravity>(id);
                        delete_components_by_entity_id<Controller>(id);
                        delete_components_by_entity_id<Speed>(id);
                        delete_components_by_entity_id<Sprite>(id);
                        delete_components_by_entity_id<Size>(id);
                        delete_components_by_entity_id<BoxCollider>(id);
                        delete_components_by_entity_id<SpawnWithInput>(id);
                        delete_components_by_entity_id<Parralax>(id);
                        delete_components_by_entity_id<Send>(id);
                        delete_components_by_entity_id<OnCollideStop>(id);
                        delete_components_by_entity_id<AddForce>(id);
                        delete_components_by_entity_id<ShowCollisionsWithInput>(id);
                        delete_components_by_entity_id<Text>(id); 
                        
                        delete_components_by_entity_id<Id>(id);
                        it->delete_entity();
                        entities.erase(it);
                        break;
                    }
                }
            }

            template <typename Component>
            void add_component(Entity entity, Component&& component) {
                auto& components = get_components<Component>();
                components.insert_at(entity.get_id(), std::forward<Component>(component));
            }

            template <typename Component>
            void add_component_from_prefab(Entity entity, Component component) {
                auto& components = get_components<Component>();
                components.insert_at(entity.get_id(), std::forward<Component>(component));
            }

            template <typename Component>
            void delete_components_by_entity_id(size_t id) {
                auto& components = get_components<Component>();
                components.erase(id);
            }

            void run_systems() {
                while (_window->isOpen()) {
                    for (auto& system : systems) {
                        system(*this);
                    }
                }
            }

            template <typename Function, typename... Args>
            void add_system(Function&& f, Args&&... args) {
                systems.emplace_back([=](Registry& registry) {
                    f(registry, std::forward<Args>(args)...);
                });
            }

            std::vector<std::any> get_prefab(std::string name) {
                return _prefabs[name];
            }

        public:
            std::shared_ptr<sf::RenderWindow> _window;
            sf::Event _event;
            std::unordered_map<std::string, std::vector<std::any>> _prefabs;
        private:
            std::unordered_map<std::type_index, std::any> _components_arrays;
            std::vector<Entity> entities;
            std::vector<std::function<void(Registry&)>> systems;
    };
#endif /* !REGISTRY_HPP_ */