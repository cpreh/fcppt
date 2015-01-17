//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_MOVE_CONSTRUCT_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_MOVE_CONSTRUCT_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

class move_construct
{
	FCPPT_NONASSIGNABLE(
		move_construct
	);
public:
	typedef void *result_type;

	explicit
	move_construct(
		void *const _store
	)
	:
		store_(
			_store
		)
	{
	}

	template<
		typename T
	>
	result_type
	operator()(
		T &&_t
	) const
	{
		return
			new (
				store_
			)
			typename std::remove_reference<
				T
			>::type(
				std::move(
					_t
				)
			);
	}
private:
	void *const store_;
};

}
}
}

#endif
