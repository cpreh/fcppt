//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/reference.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/cast/apply.hpp>
#include <fcppt/cast/bad_dynamic.hpp>
#include <fcppt/cast/dynamic.hpp>
#include <fcppt/cast/dynamic_exn.hpp>
#include <fcppt/cast/dynamic_fun.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

struct base
{
	FCPPT_NONCOPYABLE(
		base
	);

	base()
	{
	}

	virtual
	~base()
	{
	}
};

struct derived1
:
	base
{
	FCPPT_NONCOPYABLE(
		derived1
	);

	derived1()
	{
	}

	~derived1()
	override
	{
	}
};

struct derived2
:
	base
{
	FCPPT_NONCOPYABLE(
		derived2
	);

	derived2()
	{
	}

	~derived2()
	override
	{
	}
};

}

TEST_CASE(
	"cast::dynamic"
	"[cast]"
)
{
	derived1 d1{};

	derived2 d2{};

	base &b1{
		d1
	};

	base &b2{
		d2
	};

	CHECK(
		fcppt::cast::dynamic<
			derived1
		>(
			b1
		)
		==
		fcppt::optional::make(
			fcppt::make_ref(
				d1
			)
		)
	);

	CHECK(
		fcppt::cast::apply<
			fcppt::cast::dynamic_fun,
			derived1
		>(
			b1
		)
		==
		fcppt::optional::make(
			fcppt::make_ref(
				d1
			)
		)
	);

	CHECK(
		fcppt::cast::dynamic<
			derived1
		>(
			b2
		)
		==
		fcppt::optional::object<
			fcppt::reference<
				derived1
			>
		>{}
	);

	CHECK(
		&fcppt::cast::dynamic_exn<
			derived1 &
		>(
			b1
		)
		==
		&d1
	);

	CHECK_THROWS_AS(
		fcppt::cast::dynamic_exn<
			derived1 &
		>(
			b2
		),
		fcppt::cast::bad_dynamic
	);
}
