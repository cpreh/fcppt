//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/unique_ptr_dynamic_cast.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/dynamic_fun.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/holds_type.hpp>
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
	:
		base()
	{
	}

	~derived()
	override
	{
	}
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	unique_ptr_to_base
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::unique_ptr<
		base
	>
	base_unique_ptr;

	typedef
	fcppt::unique_ptr<
		derived
	>
	derived_unique_ptr;

	BOOST_CHECK(
		fcppt::variant::holds_type<
			base_unique_ptr
		>(
			fcppt::unique_ptr_dynamic_cast<
				fcppt::cast::dynamic_fun,
				derived
			>(
				fcppt::make_unique_ptr<
					base
				>()
			)
		)
	);

	BOOST_CHECK(
		fcppt::variant::holds_type<
			derived_unique_ptr
		>(
			fcppt::unique_ptr_dynamic_cast<
				fcppt::cast::dynamic_fun,
				derived
			>(
				fcppt::unique_ptr_to_base<
					base
				>(
					fcppt::make_unique_ptr<
						derived
					>()
				)
			)
		)
	);
}
