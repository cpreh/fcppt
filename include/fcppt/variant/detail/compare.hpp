//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_COMPARE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_COMPARE_HPP_INCLUDED

#include <fcppt/const.hpp>
#include <fcppt/maybe.hpp>
#include <fcppt/nonassignable.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/to_optional.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Types,
	typename Compare
>
class compare
{
	FCPPT_NONASSIGNABLE(
		compare
	);
public:
	typedef
	fcppt::variant::object<
		Types
	> variant_type;

	compare(
		variant_type const &_left,
		Compare const &_compare
	)
	:
		left_(
			_left
		),
		compare_(
			_compare
		)
	{
	}

	typedef bool result_type;

	template<
		typename OtherType
	>
	result_type
	operator()(
		OtherType const &_right
	) const
	{
		return
			fcppt::maybe(
				fcppt::variant::to_optional<
					OtherType
				>(
					left_
				),
				fcppt::const_(
					false
				),
				[
					&_right,
					this
				](
					OtherType const &_left
				)
				{
					return
						compare_(
							_left,
							_right
						);
				}
			);
	}
private:
	variant_type const &left_;

	Compare const compare_;
};

}
}
}

#endif
