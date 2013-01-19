//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_PTR_EQUAL_HPP_INCLUDED
#define FCPPT_CONTAINER_PTR_EQUAL_HPP_INCLUDED

namespace fcppt
{
namespace container
{
namespace ptr
{

/**
\brief A functor that compares an element in a ptr_container to a pointer
\ingroup fcpptcontainerptr
*/
template<
	typename Ptr
>
class equal
{
public:
	typedef bool result_type;

	/**
	\brief Constructs the functor

	Constructs the functor from \a _ptr

	\param _ptr The pointer to compare to
	*/
	explicit equal(
		Ptr const _ptr
	)
	:
		ptr_(_ptr)
	{}

	/**
	\brief Compares the address of a value to the pointer

	Compares the address of \a _val to the pointer.

	\param _val The value to compare the address of
	*/
	template<
		typename Val
	>
	result_type
	operator()(
		Val const &_val
	) const
	{
		return &_val == ptr_;
	}
private:
	Ptr ptr_;
};

}
}
}

#endif
