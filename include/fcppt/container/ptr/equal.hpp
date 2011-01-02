//          Copyright Carl Philipp Reh 2009 - 2011.
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

template<
	typename Ptr
>
class equal
{
public:
	typedef bool result_type;

	explicit equal(
		Ptr const _ptr
	)
	:
		ptr_(_ptr)
	{}

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
