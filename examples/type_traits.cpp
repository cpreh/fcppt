//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/generate_has_member_function.hpp>
#include <fcppt/type_traits/generate_has_type.hpp>
#include <fcppt/type_traits/is_float_or_double.hpp>
#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

namespace
{

// ![generate_has_member_function]
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
};

// apple has a worm function
static_assert(
	has_worm<
		apple,
		void (apple::*)()
	>::value,
	"apples have worms"
);

// orange doesn't have a worm function
static_assert(
	!has_worm<
		orange,
		void (orange::*)()
	>::value,
	"oranges have no worms"
);
// ![generate_has_member_function]

// ![generate_has_type]
FCPPT_TYPE_TRAITS_GENERATE_HAS_TYPE(
	iterator
);

struct normal
{
};

struct container
{
	typedef int *iterator;
};

static_assert(
	has_iterator<
		container
	>::value,
	"container has an iterator"
);

static_assert(
	!has_iterator<
		normal
	>::value,
	"normal doesn't have an iterator"
);
// ![generate_has_type]

// A function which is only valid for something "derived from" std::basic_string
template<
	typename T
>
typename
std::enable_if<
	fcppt::type_traits::is_string<
		T
	>::value,
	T
>::type
edit_string(
	T const &t
)
{
	// We know operator+ is available with basic_string
	return t + T();
}

template<
	typename T
>
typename
std::enable_if<
	fcppt::type_traits::is_float_or_double<
		T
	>::value,
	T
>::type
divide_by_1000(
	T const &t
)
{
	// Might be unsafe with integral values.
	return t * static_cast<T>(1) / static_cast<T>(1000);
}

}

FCPPT_PP_POP_WARNING

int main()
{
	std::cout << divide_by_1000(10.0) << '\n';
	// Would give a compiler error
	//std::cout << divide_by_1000(10) << '\n';
	std::string s("foobar");
	std::cout << edit_string(s) << '\n';
	// Would give a compiler error, although operator+ is defined
	//std::cout << edit_string(10) << '\n';

	apple foo;

	foo.worm();
}
//]
