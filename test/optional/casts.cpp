//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/const_cast.hpp>
#include <fcppt/optional/dynamic_cast.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
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

typedef
fcppt::optional::reference<
	base
>
optional_base_ref;

typedef
fcppt::optional::reference<
	derived
>
optional_derived_ref;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_dynamic_cast
)
{
FCPPT_PP_POP_WARNING

	optional_base_ref const empty_base{};

	optional_derived_ref const empty_derived(
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

	optional_base_ref const base_ref{
		fcppt::reference<
			base
		>(
			derived_object
		)
	};

	optional_derived_ref const derived_ref(
		fcppt::optional::dynamic_cast_<
			derived
		>(
			base_ref
		)
	);

	BOOST_CHECK_EQUAL(
		derived_ref,
		optional_derived_ref{
			fcppt::make_ref(
				derived_object
			)
		}
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_static_cast
)
{
FCPPT_PP_POP_WARNING

	optional_base_ref const empty_base{};

	optional_derived_ref const empty_derived(
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

	optional_base_ref const base_ref{
		fcppt::reference<
			base
		>(
			derived_object
		)
	};

	optional_derived_ref const derived_ref(
		fcppt::optional::static_cast_<
			derived
		>(
			base_ref
		)
	);

	BOOST_CHECK_EQUAL(
		derived_ref,
		optional_derived_ref(
			fcppt::make_ref(
				derived_object
			)
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_const_cast
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional::reference<
		base const
	>
	optional_const_base_ref;

	base object;

	optional_const_base_ref const ref(
		fcppt::make_cref(
			object
		)
	);

	optional_base_ref const nonconst_ref(
		fcppt::optional::const_cast_<
			base
		>(
			ref
		)
	);

	BOOST_CHECK_EQUAL(
		nonconst_ref,
		optional_base_ref(
			fcppt::make_ref(
				object
			)
		)
	);
}
