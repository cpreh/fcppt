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
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
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

TEST_CASE(
	"unique_ptr_dynamic_cast",
	"[smartptr]"
)
{
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

	CHECK(
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

	CHECK(
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
