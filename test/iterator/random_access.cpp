//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/iterator/base_impl.hpp>
#include <fcppt/iterator/types_from.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
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

BOOST_AUTO_TEST_CASE(
	def_ctor
)
{
	iterator it1{}, it2{};

	BOOST_CHECK(
		it1
		==
		it2
	);
}

BOOST_AUTO_TEST_CASE(
	increment_decrement
)
{
	const_iterator it{
		vec_c.begin()
	};

	++it;

	BOOST_CHECK_EQUAL(
		*it,
		"2"
	);

	BOOST_CHECK(
		&*it
		==
		&vec_c[1]
	);

	--it;

	BOOST_CHECK_EQUAL(
		*it,
		"1"
	);

	BOOST_CHECK(
		&*it
		==
		&vec_c[0]
	);

	BOOST_CHECK(
		&*it++
		==
		&vec_c[0]
	);

	BOOST_CHECK(
		&*it
		==
		&vec_c[1]
	);

	BOOST_CHECK(
		&*it--
		==
		&vec_c[1]
	);

	BOOST_CHECK(
		&*it
		==
		&vec_c[0]
	);
}

BOOST_AUTO_TEST_CASE(
	test_swap
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

	BOOST_CHECK_EQUAL(
		*it1,
		"2"
	);

	BOOST_CHECK_EQUAL(
		*it2,
		"1"
	);
}

BOOST_AUTO_TEST_CASE(
	test_advance
)
{
	const_iterator it{
		vec_c.begin()
	};

	BOOST_REQUIRE(
		&*(it += 2)
		==
		&vec_c[2]
	);

	BOOST_REQUIRE(
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

		BOOST_CHECK_EQUAL(
			&*temp,
			&vec_c[2]
		);

		BOOST_CHECK(
			temp
			==
			it
		);
	}

	BOOST_CHECK(
		2
		+
		const_iterator{
			vec_c.begin()
		}
		==
		it
	);

	BOOST_CHECK(
		it
		-
		2
		==
		const_iterator{
			vec_c.begin()
		}
	);

	it -= 1;

	BOOST_CHECK(
		&*it
		==
		&vec_c[1]
	);

	BOOST_CHECK(
		&vec_c.begin()[
			1
		]
		==
		&vec_c[1]
	);
}

BOOST_AUTO_TEST_CASE(
	test_write
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

	BOOST_CHECK_EQUAL(
		*it,
		"11"
	);
}

BOOST_AUTO_TEST_CASE(
	comparison
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

	BOOST_CHECK_EQUAL(
		it1
		-
		it2,
		-1
	);

	BOOST_CHECK_EQUAL(
		it2
		-
		it1,
		1
	);

	BOOST_CHECK(
		it1
		<
		it2
	);

	BOOST_CHECK(
		it1
		<=
		it2
	);

	BOOST_CHECK(
		it2
		>
		it1
	);

	BOOST_CHECK(
		it2
		>=
		it1
	);


	BOOST_CHECK(
		it1
		!=
		it2
	);
}
