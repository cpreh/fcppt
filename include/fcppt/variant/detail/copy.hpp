//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_COPY_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_COPY_HPP_INCLUDED

#include <fcppt/variant/raw_type.hpp>
#include <fcppt/nonassignable.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{

class copy
{
	FCPPT_NONASSIGNABLE(copy)
public:
	typedef void *result_type;

	explicit copy(
		raw_type *const _store
	)
	:
		store_(_store)
	{}

	template<
		typename T
	>
	result_type
	operator()(
		T const &_t
	) const
	{
		return new (store_) T(_t);
	}
private:
	raw_type *const store_;
};

}
}
}

#endif
