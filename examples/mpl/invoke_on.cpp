//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [mpl_invoke_on]
// In the following example, we are going to create a function that can
// transform a color type given at runtime (defined via an enum) into a static
// color type (represented by variant over static color types).
#include <fcppt/tag.hpp>
#include <fcppt/cast/enum_to_underlying.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/mpl/invoke_on.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <cassert>
#include <exception>
#include <fcppt/config/external_end.hpp>


namespace
{

// Our color enum
enum class color_enum
{
	bgr,
	rgb
	// + more color types
};

// Our static color types
struct bgr
{
};

struct rgb
{
};

// Typedef the available static color types
typedef
boost::mpl::vector2<
	bgr,
	rgb
> static_color_types;

// The variant type that can hold any of the static color types
typedef
fcppt::variant::object<
	static_color_types
>
color_variant;

// Transforms a concrete color type into a color_variant. This functor will be
// used with invoke_on.
struct create_functor
{
	typedef color_variant result_type;

	template<
		typename ConcreteColor
	>
	result_type
	operator()(
		fcppt::tag<
			ConcreteColor
		>
	) const
	{
		return
			color_variant(
				ConcreteColor()
			);
	}
};

// Transforms a color enum into a static color type using invoke_on
color_variant
make_color_variant(
	color_enum const _value
)
{
	return
		fcppt::mpl::invoke_on<
			static_color_types
		>(
			fcppt::cast::to_unsigned(
				fcppt::cast::enum_to_underlying(
					_value
				)
			),
			create_functor(),
			[]()
			-> color_variant
			{
				std::terminate();
			}
		);
}

}

int
main()
{
	color_variant const variant(
		make_color_variant(
			color_enum::rgb
		)
	);

	assert(
		fcppt::variant::holds_type<
			rgb
		>(
			variant
		)
	);
}
//! [mpl_invoke_on]
