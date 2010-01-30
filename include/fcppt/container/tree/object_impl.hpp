//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/container/tree/object_decl.hpp>
#include <fcppt/container/ptr_equal.hpp>
#include <fcppt/make_auto_ptr.hpp>
#include <fcppt/algorithm/find_if_exn.hpp>

template<
	typename T
>
fcppt::container::tree::object<T>::object()
:
	value_(),
	parent_(0)
{}

template<
	typename T
>
fcppt::container::tree::object<T>::object(
	T const &value_
)
:
	value_(value_),
	parent_(0)
{}

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
	return parent_;
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::parent(
	object &t
)
{
	parent_ = &t;
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::orphan()
{
	if(!has_parent())
		return;

	parent->release(
		*this
	);

	parent_ = 0;
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::auto_ptr
fcppt::container::tree::object<T>::release(
	iterator const it
)
{
	return children.release(
		it
	);
}

template<
	typename T
>
typename fcppt::container::tree::object<T>::iterator
fcppt::container::tree::object<T>::child_position()
{
	return algorithm::find_if_exn(
		parent().begin(),
		parent().end(),
		make_ptr_equal(
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
	return const_iterator(
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
	T const &v
)
{
	value_ = v;
}

template<
	typename T
>
T &
fcppt::container::tree::object<T>::value()
{
	return value_;
}

template<
	typename T
>
T const &
fcppt::container::tree::object<T>::value() const
{
	return value_;
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::push_back(
	auto_ptr r
)
{
	insert(
		end(),
		r
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::push_back(
	T const &t
)
{
	insert(
		end(),
		t
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
	auto_ptr r
)
{
	insert(
		begin(),
		r
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::push_front(
	T const &t
)
{
	insert(
		begin(),
		t
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
	return children.front();
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
	return children.rend();
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
void
fcppt::container::tree::object<T>::insert(
	iterator const it,
	auto_ptr r
)
{
	object<T> &ref(*r);

	children().insert(
		it,
		r
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
	iterator const it,
	T const &t
)
{
	auto_ptr ptr(
		make_auto_ptr<
			object<T>
		>(
			t
		)
	);

	insert(
		it,
		ptr
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::erase(
	iterator const it
)
{
	children().erase(
		it
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<T>::erase(
	iterator const beg,
	iterator const end
)
{
	children().erase(
		beg,
		end
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

#endif
