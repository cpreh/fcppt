//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_CONSTRUCT_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_CONSTRUCT_HPP_INCLUDED

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Variant
>
struct construct
{
	typedef void result_type;

	explicit construct(
		Variant &obj
	)
	:
		obj(obj)
	{}

	template<
		typename T
	>
	result_type
	operator()(
		T const &t
	) const
	{
		obj = t;
	}
private:
	Variant &obj;
};

}
}
}

#endif
