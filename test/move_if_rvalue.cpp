//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::unique_ptr<
	int
>
int_unique_ptr;

static_assert(
	std::is_same<
		decltype(
			fcppt::move_if_rvalue<
				int_unique_ptr
			>(
				std::declval<
					int_unique_ptr &
				>()
			)
		),
		fcppt::unique_ptr<
			int
		> &&
	>::value,
	""
);

static_assert(
	std::is_same<
		decltype(
			fcppt::move_if_rvalue<
				int &
			>(
				std::declval<
					float &
				>()
			)
		),
		float &
	>::value,
	""
);

static_assert(
	std::is_same<
		decltype(
			fcppt::move_if_rvalue<
				int &
			>(
				std::declval<
					int
				>()
			)
		),
		int &&
	>::value,
	""
);

class container
{
	FCPPT_NONCOPYABLE(
		container
	);
public:
	container()
	:
		val_(
			fcppt::make_unique_ptr<
				int
			>(
				10
			)
		)
	{
	}

	~container()
	{
	}

	int_unique_ptr &
	get()
	{
		return
			val_;
	}
private:
	int_unique_ptr val_;
};

template<
	typename Arg
>
int_unique_ptr
test_move(
	Arg &&_arg
)
{
	return
		fcppt::move_if_rvalue<
			Arg
		>(
			_arg.get()
		);
}

int_unique_ptr
take_arg(
	int_unique_ptr &&_arg
)
{
	return
		std::move(
			_arg
		);
}

}

BOOST_AUTO_TEST_CASE(
	move_if_rvalue
)
{

	{
		int_unique_ptr const foo(
			test_move(
				container()
			)
		);

		BOOST_CHECK_EQUAL(
			*foo,
			10
		);
	}

	{
		int_unique_ptr const foo(
			take_arg(
				test_move(
					container()
				)
			)
		);

		BOOST_CHECK_EQUAL(
			*foo,
			10
		);
	}
}
