//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_RAW_VECTOR_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/container/raw_vector/object_fwd.hpp>
#include <fcppt/container/raw_vector/rep_fwd.hpp>
#include <fcppt/type_traits/is_input_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace raw_vector
{

/**
\brief A special vector class that can handle uninitialized memory.

\ingroup fcpptcontainerraw_vector

\tparam T A POD type.

\tparam A The allocator type.

See the \link fcpptcontainerraw_vector module documentation \endlink for more
information.
*/
template<
	typename T,
	typename A
>
class object
{
	static_assert(
		std::is_pod<
			T
		>::value,
		"T must be a POD type"
	);

	FCPPT_NONCOPYABLE(
		object
	);
public:
	typedef
	T
	value_type;

	typedef
	A
	allocator_type;

	typedef
	typename
	A::size_type
	size_type;

	typedef
	typename
	A::difference_type
	difference_type;

	typedef
	typename
	A::pointer
	pointer;

	typedef
	typename
	A::const_pointer
	const_pointer;

	typedef
	typename
	A::reference
	reference;

	typedef
	typename
	A::const_reference
	const_reference;

	typedef
	pointer
	iterator;

	typedef
	const_pointer
	const_iterator;

	iterator
	begin()
	noexcept;

	const_iterator
	begin() const
	noexcept;

	iterator
	end()
	noexcept;

	const_iterator
	end() const
	noexcept;

	reference
	operator[](
		size_type
	)
	noexcept;

	const_reference
	operator[](
		size_type
	) const
	noexcept;

	reference
	front()
	noexcept;

	const_reference
	front() const
	noexcept;

	reference
	back()
	noexcept;

	const_reference
	back() const
	noexcept;

	/**
	\brief Returns the pointer to the store.
	*/
	pointer
	data()
	noexcept;

	/**
	\brief Returns the pointer to the store.
	*/
	const_pointer
	data() const
	noexcept;

	/**
	\brief Returns the pointer to the end of the store.

	Equal to <code>data() + size()</code>.
	*/
	pointer
	data_end()
	noexcept;

	/**
	\brief Returns the pointer to the end of the store.

	Equal to <code>data() + size()</code>.
	*/
	const_pointer
	data_end() const
	noexcept;

	explicit
	object(
		A const &a = A()
	);

	object(
		size_type sz,
		T const &value,
		A const &a = A()
	);

	template<
		typename In
	>
	object(
		In beg,
		In end,
		A const &a = A()
	);

	/**
	\brief Reuse the storage of another container.
	*/
	explicit
	object(
		fcppt::container::raw_vector::rep<
			A
		> const &
	)
	noexcept;

	explicit
	object(
		std::initializer_list<
			value_type
		>,
		A const &a = A()
	);

	object(
		object &&
	)
	noexcept;

	~object()
	noexcept;

	object &
	operator=(
		object &&
	)
	noexcept;

	void
	push_back(
		T const &
	);

	void
	pop_back()
	noexcept;

	void
	clear()
	noexcept;

	size_type
	size() const
	noexcept;

	bool
	empty() const
	noexcept;

	size_type
	capacity() const
	noexcept;

	void
	swap(
		object &
	)
	noexcept;

	void
	resize(
		size_type sz,
		T const &value
	);

	void
	reserve(
		size_type sz
	);

	allocator_type
	get_allocator() const;

	iterator
	insert(
		iterator position,
		T const &t
	);

	void
	insert(
		iterator position,
		size_type sz,
		T const &value
	);

	template<
		typename In
	>
	void
	insert(
		iterator position,
		In beg,
		In end
	);

	iterator
	erase(
		iterator position
	)
	noexcept;

	iterator
	erase(
		iterator first,
		iterator last
	)
	noexcept;

	void
	shrink_to_fit();
private:
/// \cond
	template<
		typename In
	>
	typename
	std::enable_if<
		fcppt::type_traits::is_input_iterator<
			In
		>::value,
		void
	>::type
	insert_impl(
		iterator position,
		In begin,
		In end
	);

	template<
		typename In
	>
	typename
	std::enable_if<
		!fcppt::type_traits::is_input_iterator<
			In
		>::value,
		void
	>::type
	insert_impl(
		iterator position,
		In begin,
		In end
	);

	size_type
	new_capacity(
		size_type new_size
	) const
	noexcept;

	void
	reallocate(
		size_type new_cap
	);

	void
	set_pointers(
		pointer src,
		size_type sz,
		size_type cap
	)
	noexcept;

	void
	deallocate()
	noexcept;

	class impl
	{
		FCPPT_NONCOPYABLE(
			impl
		);
	public:
		explicit
		impl(
			A const &
		)
		noexcept;

		explicit
		impl(
			fcppt::container::raw_vector::rep<
				A
			> const &
		)
		noexcept;

		impl(
			impl &&
		)
		noexcept;

		impl &
		operator=(
			impl &&
		)
		noexcept;

		~impl()
		noexcept;

		void
		reset_pointers()
		noexcept;

		A alloc_;

		pointer
			first_,
	        	last_,
			cap_;
	};

	explicit
	object(
		impl &&
	);

	impl impl_;
/// \endcond
};

/**
\ingroup fcpptcontainerraw_vector
*/
template<
	typename T,
	typename A
>
void
swap(
	fcppt::container::raw_vector::object<
		T,
		A
	> &,
	fcppt::container::raw_vector::object<
		T,
		A
	> &
)
noexcept;

}
}
}

#endif
