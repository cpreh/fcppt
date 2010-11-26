//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/vector.hpp>
#include <fcppt/math/compare.hpp>
#include <fcppt/math/pi.hpp>
#include <fcppt/math/size_type.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>

namespace
{

typedef fcppt::math::vector::static_<
	unsigned,
	2
>::type ui2_vec;

typedef float float_type;

typedef fcppt::math::vector::static_<
	float_type,
	2
>::type f2_vec;

}

BOOST_AUTO_TEST_CASE(vector_compare)
{
	ui2_vec const
		vec1(1, 2),
		vec2(1, 2),
		vec3(2, 2);
	
	BOOST_CHECK(
		vec1 == vec2
	);

	BOOST_CHECK(
		vec2 != vec3
	);
}

BOOST_AUTO_TEST_CASE(vector_angle_between)
{
	f2_vec const
		vec1(1.f, 0.f),
		vec2(0.f, 1.f);
	
	BOOST_CHECK(
		fcppt::math::compare(
			fcppt::math::vector::angle_between(
				vec1,
				vec2
			),
			fcppt::math::pi<float_type>() / 2.f
		)
	);
}

BOOST_AUTO_TEST_CASE(vector_angle_between_cast)
{
	ui2_vec const
		vec1(1, 0),
		vec2(0, 1);
	
	BOOST_CHECK(
		fcppt::math::compare(
			fcppt::math::vector::angle_between_cast<
				float_type
			>(
				vec1,
				vec2
			),
			fcppt::math::pi<float_type>() / 2.f
		)
	);
}


BOOST_AUTO_TEST_CASE(vector_swap)
{
	ui2_vec vec1(
		1u,
		2u
	);

	ui2_vec vec2(
		3u,
		4u
	);

	std::swap(
		vec1,
		vec2
	);

	BOOST_REQUIRE(
		vec1
		==
		ui2_vec(
			3u,
			4u
		)
	);

	BOOST_REQUIRE(
		vec2
		==
		ui2_vec(
			1u,
			2u
		)
	);
}

BOOST_AUTO_TEST_CASE(vector_unit_circle)
{
	BOOST_REQUIRE(
		fcppt::math::vector::unit_circle(
			fcppt::math::pi<
				float_type
			>()
		)
		==
		f2_vec(
			-1.f,
			0.f
		)
	);
}

BOOST_AUTO_TEST_CASE(vector_null)
{
	BOOST_REQUIRE(
		ui2_vec::null()
		== ui2_vec(0, 0)
	);
}

BOOST_AUTO_TEST_CASE(vector_arithmetic)
{
	ui2_vec vec(0, 0);

	vec += ui2_vec(1, 2);

	BOOST_REQUIRE(
		vec == ui2_vec(1, 2)
	);

	vec *= 2;

	BOOST_REQUIRE(
		vec == ui2_vec(2, 4)
	);

	vec /= 2;

	BOOST_REQUIRE(
		vec == ui2_vec(1, 2)
	);
}

namespace
{

template<
	typename T
>
class view_storage
{
public:
	typedef T value_type;
	typedef fcppt::math::size_type size_type;
	typedef value_type *pointer;

	explicit view_storage(
		pointer const data_,
		size_type const size_
	)
	:
		data_(data_),
		size_(size_)
	{}

	pointer
	data() const
	{
		return data_;
	}

	size_type
	size() const
	{
		return size_;
	}
private:
	pointer data_;
	size_type size_;
};

}

BOOST_AUTO_TEST_CASE(vector_construct)
{
	typedef view_storage<
		unsigned
	> unsigned_view_storage;

	typedef fcppt::math::vector::basic<
		unsigned,
		boost::mpl::integral_c<
			fcppt::math::size_type,
			2
		>,
		view_storage<
			unsigned
		>
	> view_vector;

	unsigned data[] = { 1, 2 };

	view_vector const view(
		unsigned_view_storage(
			data,
			sizeof(data) / sizeof(unsigned)
		)
	);

	ui2_vec const vec(
		view
	);

	BOOST_REQUIRE(
		vec == view
	);
}

BOOST_AUTO_TEST_CASE(vector_structure_cast)
{
	ui2_vec const vec(
		1,
		2
	);

	BOOST_REQUIRE(
		fcppt::math::vector::structure_cast<
			f2_vec
		>(
			vec
		)
		== f2_vec(
			1.f,
			2.f
		)
	);
}
