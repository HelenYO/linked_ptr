//
// Created by Елена on 08/02/2019.
//

#ifndef LINKED_PTR_LINKED_PTR_H
#define LINKED_PTR_LINKED_PTR_H

#include <iostream>

namespace {

    struct info_base {
        virtual void destroy() = 0;
        virtual ~info_base() = default;

        info_base *left = nullptr;
        info_base *right = nullptr;
    };

    template <typename T>
    struct info : info_base {

        T *get() {
            return ptr;
        }

        void destroy() {
            //delete ptr;
            ptr = nullptr;
        }

        info(T *ptr) :ptr(ptr){}

        ~info() {
            if(ptr) {
                destroy();
            }
        }

        T *ptr;
    };

    template<typename T>
    struct linked_ptr {

    public:

        linked_ptr() {
            set_pointers(nullptr, nullptr);
        }

        explicit linked_ptr(T *p) {
            set_pointers(p, nullptr);
            data = new info<T>(ptr);
        }

        linked_ptr(std::nullptr_t) {
            set_pointers(nullptr, nullptr);
        }

        template<typename Y>
        linked_ptr(linked_ptr<Y> &other) {
            set_pointers(other.ptr, nullptr);
            data = new info<T>(other.ptr);
            add_ref(other);
        }

        linked_ptr(linked_ptr &other) {
            set_pointers(other.ptr, nullptr);
            data = new info<T>(other.ptr);
            add_ref(other);
        }

        template<typename Y>
        linked_ptr &operator=(linked_ptr<Y> &other) {
            linked_ptr temp(other);
            swap(temp);
            return *this;
        }

        linked_ptr &operator=(linked_ptr &other) {
            linked_ptr temp(other);
            swap(temp);
            return *this;
        }

        template<typename Y>
        linked_ptr(linked_ptr<Y> &other, T *p) {//todo: что от меня хотят?
            set_pointers(p, other.data);
            if (other.data) {
                add_ref(other);
            }
        }

        linked_ptr(linked_ptr &&other) {
            set_pointers(other.ptr, other.data);
            other.set_pointers(nullptr, nullptr);
        }

        linked_ptr &operator=(linked_ptr &&other) {
            linked_ptr temp(std::move(other));
            swap(temp);
            return *this;
        }

        template<typename Y>
        void reset(Y *p) {
            linked_ptr temp(p);
            swap(temp);
        }

        void reset() {
            linked_ptr temp;
            swap(temp);
        }

        T *get() const {
            return ptr;
        }

        T *operator->() const {
            return get();
        }

        T &operator*() const {
            return *get();
        }

        bool unique() const {
            return (!data || !(data->left || data->right));
        }

        operator bool() const {
            return get() != nullptr;
        }

        ~linked_ptr() {

            if (!data) {
                return;
            }
            if (data->right || data->left) {
                delete_this_ptr();
            }
            data->destroy();
        }


        void swap(linked_ptr &other) {
            std::swap(ptr, other.ptr);
            std::swap(data, other.data);
        }


    private:
        template<typename S>
        void add_ref(linked_ptr<S> &p) {
            if(p.data->left) {
                data->right = p.data;
                p.data->left->right = data;
                p.data->left = data;
            } else {
                data->left = nullptr;
                p.data->left = data;
            }
        }

        void delete_this_ptr() {
            if(data) {
                if (data->left) {
                    data->left->right = data->right;
                }
                if (data->right) {
                    data->right->left = data->left;
                }
            }
        }

        void set_pointers(T *p, info_base *d) {
            ptr = p;
            data = d;
        }

    private:
        T *ptr;
        info_base *data;
    };
}

#endif //LINKED_PTR_LINKED_PTR_H
