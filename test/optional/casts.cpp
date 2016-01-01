//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/optional/const_cast.hpp>
#include <fcppt/optional/dynamic_cast.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/static_cast.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

class base
{
	FCPPT_NONCOPYABLE(
		base
	);
public:
	base()
	{
	}

	virtual
	~base()
	{
	}
};

class derived
:
	public base
{
	FCPPT_NONCOPYABLE(
		derived
	);
public:
	derived()
	{
	}

	~derived()
	{
	}
};

typedef fcppt::optional::object<
	base &
> optional_base_ref;

typedef fcppt::optional::object<
	derived &
> optional_derived_ref;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_dynamic_cast
)
{
FCPPT_PP_POP_WARNING

	optional_base_ref empty_base;

	optional_derived_ref empty_derived(
		fcppt::optional::dynamic_cast_<
			derived
		>(
			empty_base
		)
	);

	BOOST_CHECK(
		!empty_derived.has_value()
	);

	derived derived_object;

	optional_base_ref base_ref(
		derived_object
	);

	optional_derived_ref derived_ref(
		fcppt::optional::dynamic_cast_<
			derived
		>(
			base_ref
		)
	);

	BOOST_CHECK(
		derived_ref.has_value()
	);

	BOOST_CHECK_EQUAL(
		&derived_ref.get_unsafe(),
		&derived_object
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_static_cast
)
{
FCPPT_PP_POP_WARNING

	optional_base_ref empty_base;

	optional_derived_ref empty_derived(
		fcppt::optional::static_cast_<
			derived
		>(
			empty_base
		)
	);

	BOOST_CHECK(
		!empty_derived.has_value()
	);

	derived derived_object;

	optional_base_ref base_ref(
		derived_object
	);

	optional_derived_ref derived_ref(
		fcppt::optional::static_cast_<
			derived
		>(
			base_ref
		)
	);

	BOOST_CHECK(
		derived_ref.has_value()
	);

	BOOST_CHECK_EQUAL(
		&derived_ref.get_unsafe(),
		&derived_object
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_const_cast
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::optional::object<
		base const &
	> optional_const_base_ref;

	base object;

	optional_const_base_ref const ref(
		object
	);

	optional_base_ref const nonconst_ref(
		fcppt::optional::const_cast_<
			base
		>(
			ref
		)
	);

	BOOST_CHECK(
		nonconst_ref.has_value()
	);

	BOOST_CHECK_EQUAL(
		&nonconst_ref.get_unsafe(),
		&object
	);
}
