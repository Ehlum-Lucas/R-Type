#ifndef REGISTRY_HPP_
    #define REGISTRY_HPP_

    #include <typeindex>
    #include <functional>
    #include "SparseArray.hpp"
    #include "Entity.hpp"
    #include "Components.hpp"
    #include <unordered_map>
    #include <any>

    class Registry {
        public:

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
                        delete_components_by_entity_id<Controllable>(id);
                        delete_components_by_entity_id<Type>(id);
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
            void delete_components_by_entity_id(size_t id) {
                auto& components = get_components<Component>();
                components.erase(id);
            }

            void run_systems() {
                for (auto& system : systems) {
                    system(*this);
                }
            }

            template <typename Function, typename... Args>
            void add_system(Function&& f, Args&&... args) {
                systems.emplace_back([=](Registry& registry) {
                    f(registry, std::forward<Args>(args)...);
                });
            }

            void reset() {
                _components_arrays.clear();
                entities.clear();
                systems.clear();
            }

        private:
            std::unordered_map<std::type_index, std::any> _components_arrays;
            std::vector<Entity> entities;
            std::vector<std::function<void(Registry&)>> systems;
    };
#endif /* !REGISTRY_HPP_ */