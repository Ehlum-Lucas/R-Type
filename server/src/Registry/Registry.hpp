#ifndef REGISTRY_HPP_
    #define REGISTRY_HPP_

    #include <typeindex>
    #include <functional>
    #include "SparseArray.hpp"
    #include "Entity.hpp"
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
                entities.emplace_back(next_entity_id++);
                return entities.back();
            }

            template <typename Component>
            void add_component(Entity entity, Component&& component) {
                auto& components = get_components<Component>();
                components.insert_at(entity.get_id(), std::forward<Component>(component));
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

        private:
            std::unordered_map<std::type_index, std::any> _components_arrays;
            std::vector<Entity> entities;
            std::size_t next_entity_id = 1;
            std::vector<std::function<void(Registry&)>> systems;
    };
#endif /* !REGISTRY_HPP_ */