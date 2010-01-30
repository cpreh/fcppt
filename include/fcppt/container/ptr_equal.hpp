//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_PTR_EQUAL_HPP_INCLUDED
#define FCPPT_CONTAINER_PTR_EQUAL_HPP_INCLUDED

namespace fcppt
{
namespace container
{

template<
	typename Ptr
>
class ptr_equal
{
public:
	typedef bool result_type;

	explicit ptr_equal(
		Ptr const p
	)
	:
		p(p)
	{}

	template<
		typename Val
	>
	result_type
	operator()(
		Val const &val
	) const
	{
		return &val == p;
	}
private:
	Ptr p;
};

template<
	typename Ptr
>
ptr_equal<Ptr> const
make_ptr_equal(
	Ptr const p
)
{
	return ptr_equal<Ptr>(p);
}

}
}

#endif
