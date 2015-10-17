//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_traits/generate_has_member_function.hpp>


namespace
{

FCPPT_TYPE_TRAITS_GENERATE_HAS_MEMBER_FUNCTION(
	worm
);

struct apple
{
	void
	worm()
	{
	}
};

struct orange
{
	void
	skin()
	{
	}
};

}

int
main()
{
	static_assert(
		has_worm<
			apple,
			void(apple::*)()
		>::value,
		""
	);

	static_assert(
		!has_worm<
			orange,
			void(orange::*)()
		>::value,
		""
	);

	apple a;

	a.worm();

	orange o;

	o.skin();
}
