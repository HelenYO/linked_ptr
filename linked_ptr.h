//
// Created by Елена on 08/02/2019.
//

#ifndef LINKED_PTR_LINKED_PTR_H
#define LINKED_PTR_LINKED_PTR_H

#include <iostream>

namespace {

    struct info_base {

        info_base(){};

        info_base(info_base *left, info_base *right) : left(left), right(right) {}

        ~info_base(){}

        void insert_before(info_base *other) {
            left = other->left;
            right = other;

            if(other->left) {
                other->left->right = this;
            }
            other->left = this;
        }

        void remove() {
            if(right) {
                right->left = left;
            }
            if(left) {
                left->right = right;
            }
            left = nullptr;
            right = nullptr;
        }

        void swap(info_base *other) {


            info_base *this_left = left;
            info_base *this_right = right;
            info_base *other_left = other->left;
            info_base *other_right = other->right;

            info_base *sThis = nullptr;
            info_base *sOther = nullptr;
            if (right == other) {
                if (other->right) {
                    sThis = other->right;
                    remove();
                    this->insert_before(sThis);
                } else {
                    other->remove();
                    other->insert_before(this);
                }
            } else if(left == other) {
                if (right) {
                    sOther = right;
                    other->remove();
                    //sOther->insert_before(other);
                    other->insert_before(sOther);
                } else {
                    remove();
                    //other->insert_before(this);
                    this->insert_before(other);
                }
            } else {


                if (this_left) {
                    this_left->right = other;
                }
                if (this_right) {
                    this_right->left = other;
                }

                if (other_left) {
                    other_left->right = this;
                }
                if (other_right) {
                    other_right->left = this;
                }

                this->left = other_left;
                this->right = other_right;

                other->left = this_left;
                other->right = this_right;

            }
        }

        info_base *left = nullptr;
        info_base *right = nullptr;
    };

    template<typename T>
    struct linked_ptr {
        template<typename U>
        friend struct linked_ptr;

    public:

        linked_ptr() : ptr(nullptr), data(nullptr, nullptr) {}

        explicit linked_ptr(T *p) : ptr(p), data(nullptr, nullptr) {}

        linked_ptr(std::nullptr_t) {}

        template<typename Y>
        linked_ptr(linked_ptr<Y> &other) {
            ptr = other.ptr;
            data.insert_before(&other.data);
        }

        linked_ptr(linked_ptr &other) {
            ptr = other.ptr;
            data.insert_before(&other.data);
        }

        linked_ptr(linked_ptr const &other) : linked_ptr(const_cast<linked_ptr&>(other)){

        };

        template<typename U>
        linked_ptr(linked_ptr<U> const &other) : linked_ptr(const_cast<linked_ptr<U>&>(other)){

        };

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
        linked_ptr(linked_ptr<Y> &other, T *p) {//todo: что от меня хотят? - ничего
            this = other;
            ptr = p;
        }

        linked_ptr(linked_ptr &&other) {
//            swap(other);
//            other.data.remove();
//            other.ptr = nullptr;
            linked_ptr temp(std::move(other));
            swap(temp);
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
            return !data.left & !data.right;
        }

        operator bool() const {
            return get() != nullptr;
        }

        ~linked_ptr() {
            //destroy();
            if(unique() && ptr) {

                delete ptr;

            } else if (ptr){
                data.remove();
            }
            ptr = nullptr;
        }

        void swap(linked_ptr &other) {
            std::swap(ptr, other.ptr);
            data.swap(&other.data);
        }

        //

        bool operator==(T *t) const {
            return ptr == t;
        }

        bool operator!=(T *t) const {
            return ptr != t;
        }

        bool operator>(T *t) const {
            return ptr > t;
        }

        bool operator>=(T *t) const {
            return ptr >= t;
        }

        bool operator<(T *t) const {
            return ptr < t;
        }

        bool operator<=(T *t) const {
            return ptr <= t;
        }

        template<typename U>
        bool operator==(linked_ptr<U> const &other) const {
            return other.ptr == ptr;
        }

        template<typename U>
        bool operator!=(linked_ptr<U> const &other) const {
            return other.ptr != ptr;
        }

        template<typename U>
        bool operator<(linked_ptr<U> const &other) const {
            return other.ptr < ptr;
        }

        template<typename U>
        bool operator<=(linked_ptr<U> const &other) const {
            return other.ptr <= ptr;
        }

        template<typename U>
        bool operator>(linked_ptr<U> const &other) const {
            return other.ptr > ptr;
        }

        template<typename U>
        bool operator>=(linked_ptr<U> const &other) const {
            return other.ptr >= ptr;
        }


    private:
        T *ptr;
        info_base data;
    };

    template <typename T, typename U>
    bool operator!=(linked_ptr<T> const& a, linked_ptr<U> const& b) noexcept
    {
        return !(a == b);
    }

}

#endif //LINKED_PTR_LINKED_PTR_H
