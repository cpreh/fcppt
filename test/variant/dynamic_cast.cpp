//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/cast/dynamic_fun.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/dynamic_cast.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
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

class derived1
:
	public base
{
	FCPPT_NONCOPYABLE(
		derived1
	);
public:
	derived1()
	{
	}

	~derived1()
	override
	{
	}
};

class derived2
:
	public base
{
	FCPPT_NONCOPYABLE(
		derived2
	);
public:
	derived2()
	{
	}

	~derived2()
	override
	{
	}
};

class derived3
:
	public base
{
	FCPPT_NONCOPYABLE(
		derived3
	);
public:
	derived3()
	{
	}

	~derived3()
	override
	{
	}
};

}

BOOST_AUTO_TEST_CASE(
	variant_dynamic_cast
)
{
	typedef
	boost::mpl::vector2<
		derived1,
		derived2
	>
	derived_types;

	typedef
	fcppt::variant::object<
		fcppt::variant::dynamic_cast_types<
			derived_types
		>
	>
	result_variant;

	typedef
	fcppt::optional::object<
		result_variant
	>
	result_type;

	{
		derived1 d1{};

		base &base_ref{
			d1
		};

		result_type const result{
			fcppt::variant::dynamic_cast_<
				derived_types,
				fcppt::cast::dynamic_fun
			>(
				base_ref
			)
		};

		BOOST_CHECK_EQUAL(
			result,
			result_type{
				result_variant{
					fcppt::make_ref(
						d1
					)
				}
			}
		);
	}

	{
		derived3 d3{};

		base &base_ref{
			d3
		};

		result_type const result{
			fcppt::variant::dynamic_cast_<
				derived_types,
				fcppt::cast::dynamic_fun
			>(
				base_ref
			)
		};

		BOOST_CHECK_EQUAL(
			result,
			result_type{}
		);
	}
}

BOOST_AUTO_TEST_CASE(
	variant_dynamic_cast_const
)
{
	typedef
	boost::mpl::vector2<
		derived1 const,
		derived2 const
	>
	derived_types;

	typedef
	fcppt::variant::object<
		fcppt::variant::dynamic_cast_types<
			derived_types
		>
	>
	result_variant;

	typedef
	fcppt::optional::object<
		result_variant
	>
	result_type;

	derived2 d2{};

	base const &base_ref{
		d2
	};

	{
		result_type const result{
			fcppt::variant::dynamic_cast_<
				derived_types,
				fcppt::cast::dynamic_fun
			>(
				base_ref
			)
		};

		BOOST_CHECK_EQUAL(
			result,
			result_type{
				result_variant{
					fcppt::make_cref(
						d2
					)
				}
			}
		);
	}
}
