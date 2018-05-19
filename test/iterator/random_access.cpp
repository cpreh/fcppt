//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/iterator/base_impl.hpp>
#include <fcppt/iterator/types_from.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
std::vector<
	std::string
>
string_vector;

template<
	bool IsConst
>
using
iterator_type
=
std::conditional_t<
	IsConst,
	string_vector::const_iterator,
	string_vector::iterator
>;

template<
	bool IsConst
>
class iterator_tpl;

template<
	bool IsConst
>
using
base_type
=
fcppt::iterator::base<
	fcppt::iterator::types_from<
		iterator_tpl<
			IsConst
		>,
		iterator_type<
			IsConst
		>
	>
>;

template<
	bool IsConst
>
class iterator_tpl
:
	public
		base_type<
			IsConst
		>
{
public:
	typedef
	base_type<
		IsConst
	>
	base;

	typedef
	typename
	base::reference
	reference;

	typedef
	typename
	base::difference_type
	difference_type;

	typedef
	iterator_type<
		IsConst
	>
	impl_type;

	iterator_tpl()
	:
		impl_{}
	{
	}

	explicit
	iterator_tpl(
		impl_type const _it
	)
	:
		impl_{
			_it
		}
	{
	}

	reference
	dereference() const
	{
		return
			*impl_;
	}

	void
	increment()
	{
		++impl_;
	}

	bool
	equal(
		iterator_tpl const &_other
	) const
	{
		return
			impl_
			==
			_other.impl_;
	}

	void
	decrement()
	{
		--impl_;
	}

	void
	advance(
		difference_type const _diff
	)
	{
		impl_ +=
			_diff;
	}

	difference_type
	distance_to(
		iterator_tpl const &_other
	) const
	{
		return
			_other.impl_
			-
			impl_;
	}
private:
	impl_type impl_;
};

typedef
iterator_tpl<
	true
>
const_iterator;

typedef
iterator_tpl<
	false
>
iterator;

string_vector const vec_c{
	"1",
	"2",
	"3"
};

}

TEST_CASE(
	"iterator random access def_ctor",
	"[iterator]"
)
{
	iterator it1{}, it2{};

	CHECK(
		it1
		==
		it2
	);
}

TEST_CASE(
	"iterator random access increment_decrement"
	"[iterator]"
)
{
	const_iterator it{
		vec_c.begin()
	};

	++it;

	CHECK(
		*it
		==
		"2"
	);

	CHECK(
		&*it
		==
		&vec_c[1]
	);

	--it;

	CHECK(
		*it
		==
		"1"
	);

	CHECK(
		&*it
		==
		&vec_c[0]
	);

	CHECK(
		&*it++
		==
		&vec_c[0]
	);

	CHECK(
		&*it
		==
		&vec_c[1]
	);

	CHECK(
		&*it--
		==
		&vec_c[1]
	);

	CHECK(
		&*it
		==
		&vec_c[0]
	);
}

TEST_CASE(
	"iterator_range swap",
	"[iterator]"
)
{
	const_iterator it1{
		vec_c.begin()
	};

	const_iterator it2{
		vec_c.begin() + 1
	};

	swap(
		it1,
		it2
	);

	CHECK(
		*it1
		==
		"2"
	);

	CHECK(
		*it2
		==
		"1"
	);
}

TEST_CASE(
	"iterator random access advance",
	"[iterator]"
)
{
	const_iterator it{
		vec_c.begin()
	};

	REQUIRE(
		&*(it += 2)
		==
		&vec_c[2]
	);

	REQUIRE(
		&*it
		==
		&vec_c[2]
	);

	{
		const_iterator const temp{
			const_iterator{
				vec_c.begin()
			}
			+
			2
		};

		CHECK(
			&*temp
			==
			&vec_c[2]
		);

		CHECK(
			temp
			==
			it
		);
	}

	CHECK(
		2
		+
		const_iterator{
			vec_c.begin()
		}
		==
		it
	);

	CHECK(
		it
		-
		2
		==
		const_iterator{
			vec_c.begin()
		}
	);

	it -= 1;

	CHECK(
		&*it
		==
		&vec_c[1]
	);

	CHECK(
		&vec_c.begin()[
			1
		]
		==
		&vec_c[1]
	);
}

TEST_CASE(
	"iterator random access write",
	"[iterator]"
)
{
	string_vector vec{
		"1",
		"2",
		"3"
	};

	iterator it{
		vec.begin()
	};

	it->push_back(
		'1'
	);

	CHECK(
		*it
		==
		"11"
	);
}

TEST_CASE(
	"iterator random access comparison",
	"[iterator]"
)
{
	const_iterator it1{
		vec_c.begin()
	};

	const_iterator it2{
		vec_c.begin()
		+
		1
	};

	CHECK(
		it1
		-
		it2
		==
		-1
	);

	CHECK(
		it2
		-
		it1
		==
		1
	);

	CHECK(
		it1
		<
		it2
	);

	CHECK(
		it1
		<=
		it2
	);

	CHECK(
		it2
		>
		it1
	);

	CHECK(
		it2
		>=
		it1
	);

	CHECK(
		it1
		!=
		it2
	);
}
