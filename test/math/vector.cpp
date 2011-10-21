//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/compare.hpp>
#include <fcppt/math/pi.hpp>
#include <fcppt/math/range_compare.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/hypersphere_to_cartesian.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/vector.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{
typedef
float
real;

typedef
fcppt::math::vector::static_<unsigned,2>::type
uivector2;

typedef
fcppt::math::vector::static_<real,1>::type
fvector1;

typedef
fcppt::math::vector::static_<real,2>::type
fvector2;

typedef
fcppt::math::vector::static_<real,3>::type
fvector3;

real const epsilon =
	static_cast<real>(
		0.001);
}

BOOST_AUTO_TEST_CASE(vector_compare)
{
	uivector2 const
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
	fvector2 const
		vec1(1.f, 0.f),
		vec2(0.f, 1.f);

	BOOST_CHECK(
		fcppt::math::compare(
			fcppt::math::vector::angle_between(
				vec1,
				vec2
			),
			fcppt::math::pi<real>() / 2.f
		)
	);
}

BOOST_AUTO_TEST_CASE(vector_angle_between_cast)
{
	uivector2 const
		vec1(1, 0),
		vec2(0, 1);

	BOOST_CHECK(
		fcppt::math::compare(
			fcppt::math::vector::angle_between_cast<
				real
			>(
				vec1,
				vec2
			),
			fcppt::math::pi<real>() / 2.f
		)
	);
}

BOOST_AUTO_TEST_CASE(vector_signed_angle)
{
	fvector2 const
		vec1(2.f, 1.f),
		vec2(2.f, 2.f);

	BOOST_CHECK(
		fcppt::math::compare(
			fcppt::math::vector::signed_angle(
				vec1,
				vec2
			),
			fcppt::math::pi<real>() / 2.f
		)
	);
}

BOOST_AUTO_TEST_CASE(vector_signed_angle_cast)
{
	uivector2 const
		vec1(2, 1),
		vec2(2, 2);

	BOOST_CHECK(
		fcppt::math::compare(
			fcppt::math::vector::signed_angle_cast<
				real
			>(
				vec1,
				vec2
			),
			fcppt::math::pi<real>() / 2.f
		)
	);
}

BOOST_AUTO_TEST_CASE(vector_swap)
{
	uivector2 vec1(
		1u,
		2u
	);

	uivector2 vec2(
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
		uivector2(
			3u,
			4u
		)
	);

	BOOST_REQUIRE(
		vec2
		==
		uivector2(
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
				real
			>()
		)
		==
		fvector2(
			-1.f,
			0.f
		)
	);
}

BOOST_AUTO_TEST_CASE(vector_null)
{
	BOOST_REQUIRE(
		uivector2::null()
		== uivector2(0, 0)
	);
}

BOOST_AUTO_TEST_CASE(vector_arithmetic)
{
	uivector2 vec(0, 0);

	vec += uivector2(1, 2);

	BOOST_REQUIRE(
		vec == uivector2(1, 2)
	);

	vec *= 2;

	BOOST_REQUIRE(
		vec == uivector2(2, 4)
	);

	vec /= 2;

	BOOST_REQUIRE(
		vec == uivector2(1, 2)
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
		pointer const _data,
		size_type const _size
	)
	:
		data_(_data),
		size_(_size)
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

	uivector2 const vec(
		view
	);

	BOOST_REQUIRE(
		vec == view
	);
}

BOOST_AUTO_TEST_CASE(vector_structure_cast)
{
	uivector2 const vec(
		1,
		2
	);

	BOOST_REQUIRE(
		fcppt::math::vector::structure_cast<
			fvector2
		>(
			vec
		)
		== fvector2(
			1.f,
			2.f
		)
	);
}

BOOST_AUTO_TEST_CASE(vector_hypersphere_to_cartesian)
{
	real const
		phi1 =
			static_cast<real>(1.5),
		phi2 =
			static_cast<real>(0.5);

	fvector2 const result2 =
		fcppt::math::vector::hypersphere_to_cartesian(
			fvector1(
				phi1));

	fvector3 const result3 =
		fcppt::math::vector::hypersphere_to_cartesian(
			fvector2(
				phi1,
				phi2));

	std::cout
		<< "Testing the result of 2D hypersphere_to_cartesian.\n"
		<< "The result should be:\n"
		<<
			fvector2(
				std::cos(
					phi1),
				std::sin(
					phi1))
		<< "\n and it is:\n"
		<< result2
		<< "\n";

	BOOST_CHECK(
		fcppt::math::range_compare(
			result2,
			fvector2(
				std::cos(
					phi1),
				std::sin(
					phi1)),
			epsilon));

	std::cout
		<< "Testing the result of 3D hypersphere_to_cartesian.\n"
		<< "The result should be:\n"
		<<
			fvector3(
				std::cos(
					phi1),
				std::sin(
					phi1) *
				std::cos(
					phi2),
				std::sin(
					phi1) *
				std::sin(
					phi2))
		<< "\n and it is:\n"
		<< result3
		<< "\n";

	BOOST_CHECK(
		fcppt::math::range_compare(
			result3,
			fvector3(
				std::cos(
					phi1),
				std::sin(
					phi1) *
				std::cos(
					phi2),
				std::sin(
					phi1) *
				std::sin(
					phi2)),
			epsilon));
}
