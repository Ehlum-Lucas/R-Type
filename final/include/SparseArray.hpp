/*
** EPITECH PROJECT, 2023
** SparseArray.hpp
** File description:
** SparseArray
*/

/**
 * @file SparseArray.hpp
 * @brief This file contains the declaration of the `SparseArray` class.
 */

#ifndef SPARSEARRAY_HPP_
    #define SPARSEARRAY_HPP_
    #include <vector>
    #include <cstddef>
    #include <iostream>
    #include <algorithm>
    #include <optional>
    #include <memory>

    template <typename Component>
    class SparseArray {
        public:
            using value_type = std::optional<Component>; // optional component type
            using reference_type = value_type &;
            using const_reference_type = value_type const &;
            using container_t = std::vector<value_type>; // optionally add your allocator template here .
            using size_type = typename container_t::size_type;
            using iterator = typename container_t::iterator;
            using const_iterator = typename container_t::const_iterator;
        public:
            SparseArray() {};
            SparseArray(SparseArray const &) {}; // copy constructor
            SparseArray(SparseArray &&) noexcept {}; // move constructor
            ~SparseArray() = default;
            SparseArray & operator=(SparseArray const &other) {
                if (this != &other) {
                    _data = other._data;
                }
                return *this;
            };
            SparseArray & operator=(SparseArray &&other) noexcept {
                if (this != &other) {
                    _data = std::move(other._data);
                }
                return *this;
            }

            reference_type operator[](std::size_t idx) { return _data[idx]; }
            const_reference_type operator[](std::size_t idx) const { return _data[idx]; }

            iterator begin() {return _data.begin();};
            const_iterator begin() const {return _data.begin();};
            const_iterator cbegin() const {return _data.cbegin();};
            iterator end() {return _data.end();};
            const_iterator end() const {return _data.end();};
            const_iterator cend() const {return _data.cend();};
            size_type size() const {return _data.size();};
            reference_type insert_at(size_type pos, Component const &component) {
                if (pos >= _data.size()) {
                    _data.resize(pos + 1);
                }
                _data[pos].reset(component);
                _data[pos] = component;
                return _data[pos];
            }
            reference_type insert_at( size_type pos, Component &&component) {
                if (pos >= _data.size()) {
                    _data.resize(pos + 1);
                }
                _data[pos] = std::move(component);
                return _data[pos];
            }
            template <class... Params>
            reference_type emplace_at( size_type pos, Params &&...params) {
                if (pos >= _data.size()) {
                    _data.resize(pos + 1);
                }
                _data[pos].reset();
                return _data[pos].emplace(std::forward<Params>(params)...);
            }
            void erase(size_type pos) {
                if (pos < _data.size()) {
                    _data[pos].reset();
                }
            }
            size_type get_index(value_type const &component) const {
                auto it = std::find(_data.begin(), _data.end(), component);
                if (it != _data.end()) {
                    return std::distance(_data.begin(), it);
                }
                return -1;
            }
        private :
            container_t _data;
    };

#endif /* !SPARSEARRAY_HPP_ */
