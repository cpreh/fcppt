//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/generate_has_member_function.hpp>
#include <fcppt/type_traits/generate_has_type.hpp>
#include <fcppt/type_traits/is_iterable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

FCPPT_TYPE_TRAITS_GENERATE_HAS_MEMBER_FUNCTION(
	worm);

FCPPT_TYPE_TRAITS_GENERATE_HAS_TYPE(
	size_type);

FCPPT_PP_POP_WARNING

struct apple
{
public:
	void worm()
	{
	}
};

struct orange
{
public:
	void skin()
	{
	}

	typedef
	int
	size_type;
};
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(generate_has_member_function)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		(has_worm<apple,void(apple::*)()>::value));

	BOOST_CHECK(
		(!has_worm<orange,void(orange::*)()>::value));

	apple foo;

	foo.worm();

	orange bar;

	bar.skin();
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(generate_has_type)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		!has_size_type<apple>::value);

	BOOST_CHECK(
		has_size_type<orange>::value);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(is_iterable)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		!fcppt::type_traits::is_iterable<int>::value);

	BOOST_CHECK(
		fcppt::type_traits::is_iterable<std::vector<int> >::value);
}
