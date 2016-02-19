//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/apply_ternary.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/get_exn.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::variant::object<
	boost::mpl::vector3<
		bool,
		int,
		std::string
	>
>
variant;

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
		[](
			auto &_val
		)
		{
			_val =
				typename
				std::decay<
					decltype(
						_val
					)
				>::type{};
		},
		v1
	);

	BOOST_CHECK_EQUAL(
		fcppt::variant::get_exn<
			std::string
		>(
			v1
		),
		std::string{}
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
		[](
			auto &_val1,
			auto &_val2
		)
		{
			_val1 =
				typename
				std::decay<
					decltype(
						_val1
					)
				>::type{};

			_val2 =
				typename
				std::decay<
					decltype(
						_val2
					)
				>::type{};
		},
		v1,
		v2
	);

	BOOST_CHECK_EQUAL(
		fcppt::variant::get_exn<
			std::string
		>(
			v1
		),
		std::string{}
	);

	BOOST_CHECK_EQUAL(
		fcppt::variant::get_exn<
			int
		>(
			v2
		),
		0
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
		[](
			auto &_val1,
			auto &_val2,
			auto &_val3
		)
		{
			_val1 =
				typename
				std::decay<
					decltype(
						_val1
					)
				>::type{};

			_val2 =
				typename
				std::decay<
					decltype(
						_val2
					)
				>::type{};

			_val3 =
				typename
				std::decay<
					decltype(
						_val3
					)
				>::type{};
		},
		v1,
		v2,
		v3
	);

	BOOST_CHECK_EQUAL(
		fcppt::variant::get_exn<
			std::string
		>(
			v1
		),
		std::string{}
	);

	BOOST_CHECK_EQUAL(
		fcppt::variant::get_exn<
			int
		>(
			v2
		),
		0
	);

	BOOST_CHECK_EQUAL(
		fcppt::variant::get_exn<
			bool
		>(
			v3
		),
		false
	);
}
