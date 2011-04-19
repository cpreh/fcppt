//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/container/tree/object_decl.hpp>
#include <fcppt/container/tree/detail/assign_value.hpp>
#include <fcppt/container/tree/detail/extract_value.hpp>
#include <fcppt/container/ptr/insert_unique_ptr.hpp>
#include <fcppt/container/ptr/make_equal.hpp>
#include <fcppt/algorithm/find_if_exn.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/forward.hpp>
#include <fcppt/move.hpp>
#include <algorithm>

template<
	typename T
>
fcppt::container::tree::object<T>::object()
:
	value_(),
	parent_(0)
{
}

template<
	typename T
>
fcppt::container::tree::object<T>::object(
	arg_type _value
)
:
	value_(
		fcppt::forward<
			arg_base_type	
		>(
			_value
		)
	),
	parent_(0)
{
}

template<
	typename T
>
fcppt::container::tree::object<T>::~object()
{
	clear();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::child_list &
fcppt::container::tree::object<T>::children()
{
	return children_;
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::child_list const &
fcppt::container::tree::object<T>::children() const
{
	return children_;
}

template<
	typename T
>
fcppt::container::tree::object<T> &
fcppt::container::tree::object<T>::parent()
{
	return *parent_;
}

template<
	typename T
>
fcppt::container::tree::object<T> const &
fcppt::container::tree::object<T>::parent() const
{
	return *parent_;
}

template<
	typename T
>
fcppt::container::tree::object<T> *
fcppt::container::tree::object<T>::parent_ptr()
{
	return parent_;
}

template<
	typename T
>
fcppt::container::tree::object<T> const *
fcppt::container::tree::object<T>::parent_ptr() const
{
	return parent_;
}

template<
	typename T
>
bool
fcppt::container::tree::object<T>::has_parent() const
{
	return parent_ != 0;
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::parent(
	object &_other
)
{
	parent_ = &_other;
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::unique_ptr
fcppt::container::tree::object<T>::release(
	iterator const _it
)
{
	unique_ptr ret(
		children_.release(
			_it
		).release()
	);

	return
		fcppt::move(
			ret
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::iterator
fcppt::container::tree::object<T>::child_position()
{
	return
		algorithm::find_if_exn(
			parent().begin(),
			parent().end(),
			ptr::make_equal(
				this
			)
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::const_iterator
fcppt::container::tree::object<T>::child_position() const
{
	return
		const_iterator(
			const_cast<
				object<T> &
			>(
				*this
			)
			.child_position()
		);
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::value(
	arg_type _value
)
{
	tree::detail::assign_value(
		value_,
		fcppt::forward<
			arg_base_type	
		>(
			_value
		)
	);
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::stored_type &
fcppt::container::tree::object<T>::value()
{
	return
		tree::detail::extract_value(
			value_
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::stored_type const &
fcppt::container::tree::object<T>::value() const
{
	return
		tree::detail::extract_value(
			value_
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::holder_type &
fcppt::container::tree::object<T>::holder()
{
	return value_;
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::push_back(
	unique_ptr _ptr
)
{
	insert(
		end(),
		fcppt::move(
			_ptr
		)
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::push_back(
	arg_type _value
)
{
	insert(
		end(),
		fcppt::forward<
			arg_base_type	
		>(
			_value
		)
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::pop_back()
{
	children().pop_back();
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::push_front(
	unique_ptr _ptr
)
{
	insert(
		begin(),
		fcppt::move(
			_ptr
		)
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::push_front(
	arg_type _value
)
{
	insert(
		begin(),
		fcppt::forward<
			arg_base_type	
		>(
			_value
		)
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::pop_front()
{
	children().pop_front();
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::clear()
{
	erase(
		begin(),
		end()
	);
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::reference
fcppt::container::tree::object<T>::back()
{
	return children().back();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::const_reference
fcppt::container::tree::object<T>::back() const
{
	return children().back();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::reference
fcppt::container::tree::object<T>::front()
{
	return children().front();
}
template<
	typename T
>
typename fcppt::container::tree::object<T>::const_reference
fcppt::container::tree::object<T>::front() const
{
	return children().front();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::iterator
fcppt::container::tree::object<T>::begin()
{
	return children().begin();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::iterator
fcppt::container::tree::object<T>::end()
{
	return children().end();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::const_iterator
fcppt::container::tree::object<T>::begin() const
{
	return children().begin();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::const_iterator
fcppt::container::tree::object<T>::end() const
{
	return children().end();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::reverse_iterator
fcppt::container::tree::object<T>::rbegin()
{
	return children().rbegin();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::reverse_iterator
fcppt::container::tree::object<T>::rend()
{
	return children().rend();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::const_reverse_iterator
fcppt::container::tree::object<T>::rbegin() const
{
	return children().rbegin();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::const_reverse_iterator
fcppt::container::tree::object<T>::rend() const
{
	return children().rend();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::const_iterator
fcppt::container::tree::object<T>::cbegin() const
{
	return begin();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::const_iterator
fcppt::container::tree::object<T>::cend() const
{
	return end();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::const_reverse_iterator
fcppt::container::tree::object<T>::crbegin() const
{
	return rbegin();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::const_reverse_iterator
fcppt::container::tree::object<T>::crend() const
{
	return rend();
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::insert(
	iterator const _it,
	unique_ptr _ptr
)
{
	object<T> &ref(
		*_ptr
	);

	container::ptr::insert_unique_ptr(
		children(),
		_it,
		fcppt::move(
			_ptr
		)
	);

	ref.parent(
		*this
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::insert(
	iterator const _it,
	arg_type _value
)
{
	insert(
		_it,
		fcppt::make_unique_ptr<
			object<T>
		>(
			fcppt::forward<
				arg_base_type	
			>(
				_value
			)
		)
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::erase(
	iterator const _it
)
{
	children().erase(
		_it
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::erase(
	iterator const _begin,
	iterator const _end
)
{
	children().erase(
		_begin,
		_end
	);
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::size_type
fcppt::container::tree::object<T>::size() const
{
	return children().size();
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::size_type
fcppt::container::tree::object<T>::max_size() const
{
	return children().max_size();
}

template<
	typename T
>
bool
fcppt::container::tree::object<T>::empty() const
{
	return children().empty();
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::swap(
	object &_other
)
{
	using std::swap;

	swap(
		value_,
		_other.value_
	);

	std::swap(
		parent_,
		_other.parent_
	);

	children_.swap(
		_other.children_
	);
}

template<
	typename T
>
bool
fcppt::container::tree::operator==(
	object<T> const &_a,
	object<T> const &_b
)
{
	return
		_a.value() == _b.value()
		&& _a.children() == _b.children();
}

template<
	typename T
>
bool
fcppt::container::tree::operator!=(
	object<T> const &_a,
	object<T> const &_b
)
{
	return !(_a == _b);
}

template<
	typename T
>
void
fcppt::container::tree::swap(
	object<T> &_a,
	object<T> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
