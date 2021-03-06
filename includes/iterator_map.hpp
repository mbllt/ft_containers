#ifndef ITERATOR_MAP_HPP
#define ITERATOR_MAP_HPP

#include <functional>
#include <memory>
#include <iterator>
#include "utility.hpp"

namespace ft {

template< class T >
class iterator_map {

	public:
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef value_type*							pointer;
		typedef value_type&							reference;
		typedef Node<value_type>					node;
		typedef node*								node_pointer;

	private:

		node_pointer p;

	public:

//	--------------->> CONSTRUCTORS <<---------------

		iterator_map() {
			p->value = value_type();
			p->parent = NULL;
			p->right = NULL;
			p->left = NULL;
		}
		iterator_map(const node_pointer& new_node) : p(new_node) {}
		iterator_map(const iterator_map& copy) : p(copy.p) {}
		~iterator_map() {}

		value_type getP() const { return (p->value); }

//	------------------------------------------------


//	---------------->> OPERATORS <<-----------------

		iterator_map&		operator=(const iterator_map& src) {p = src.p; return *this;}
		reference			operator*() {return p->value;}
		pointer				operator->() {return &(p->value);}
		iterator_map&		operator++() {
			if (p->right) {
				p = p->right;
				while (p->left) {
					p = p->left;
				}
			}
			else if (p->parent) {
				node *tmp = p->parent;
				while (tmp && (p->value).first > (tmp->value).first)
					tmp = tmp->parent;
				p = tmp;
			}
			return *this;
		}

		iterator_map		operator++(const int n) {
			(void)n;
			iterator_map tmp(*this);
			operator++();
			return tmp;
		}

		iterator_map&		operator--() {
			if (p->left) {
				p = p->left;
				while (p->right) {
					p = p->right;
				}
			}
			else if (p->parent) {
				node *tmp = p->parent;
				while (tmp && (p->value).first < (tmp->value).first)
					tmp = tmp->parent;
				p = tmp;
			}
			return *this;
		}

		iterator_map		operator--(const int n) {
			(void)n;
			iterator_map tmp(*this);
			operator--();
			return tmp;
		}

		friend bool operator==(const iterator_map src, const iterator_map cmp) {return (src.getP() == cmp.getP());}

		friend bool operator!=(const iterator_map src, const iterator_map cmp) {return !(src == cmp);}

};

		template<typename A, typename B>
			bool operator==(const ft::iterator_map<A> src, const ft::iterator_map<B> cmp) {return (src.getP() == cmp.getP());}

		template<typename A, typename B>
			bool operator!=(const ft::iterator_map<A> src, const ft::iterator_map<B> cmp) {return (src.getP() != cmp.getP());}

}

#endif