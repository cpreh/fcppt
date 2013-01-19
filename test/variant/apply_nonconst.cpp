//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/apply_ternary.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

struct unary_functor
{
	typedef void result_type;

	template<
		typename T1
	>
	result_type
	operator()(
		T1 &_val
	) const
	{
		_val = T1();
	}
};

struct binary_functor
{
	typedef void result_type;

	template<
		typename T1,
		typename T2
	>
	result_type
	operator()(
		T1 &_val1,
		T2 &_val2
	) const
	{
		_val1 = T1();

		_val2 = T2();
	}
};

struct ternary_functor
{
	typedef void result_type;

	template<
		typename T1,
		typename T2,
		typename T3
	>
	result_type
	operator()(
		T1 &_val1,
		T2 &_val2,
		T3 &_val3
	) const
	{
		_val1 = T1();

		_val2 = T2();

		_val3 = T3();
	}
};

typedef fcppt::variant::object<
	boost::mpl::vector3<
		bool,
		int,
		std::string
	>
> variant;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variany_apply_nonconst_unary
)
{
FCPPT_PP_POP_WARNING

	variant v1(
		std::string(
			"foo"
		)
	);

	fcppt::variant::apply_unary(
		unary_functor(),
		v1
	);

	BOOST_CHECK(
		v1.get<
			std::string
		>()
		== ""
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variany_apply_nonconst_binary
)
{
FCPPT_PP_POP_WARNING

	variant v1(
		std::string(
			"foo"
		)
	);

	variant v2(
		42
	);

	fcppt::variant::apply_binary(
		binary_functor(),
		v1,
		v2
	);

	BOOST_CHECK(
		v1.get<
			std::string
		>()
		== ""
	);

	BOOST_CHECK(
		v2.get<
			int
		>()
		== 0
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variany_apply_nonconst_ternary
)
{
FCPPT_PP_POP_WARNING

	variant v1(
		std::string(
			"foo"
		)
	);

	variant v2(
		42
	);

	variant v3(
		true
	);

	fcppt::variant::apply_ternary(
		ternary_functor(),
		v1,
		v2,
		v3
	);

	BOOST_CHECK(
		v1.get<
			std::string
		>()
		== ""
	);

	BOOST_CHECK(
		v2.get<
			int
		>()
		== 0
	);

	BOOST_CHECK(
		v3.get<
			bool
		>()
		== false
	);
}
