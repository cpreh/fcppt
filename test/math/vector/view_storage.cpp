//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/object.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename T,
	fcppt::math::size_type N
>
class view_storage
{
public:
	typedef
	T
	value_type;

	typedef
	fcppt::math::size_type
	size_type;

	typedef
	fcppt::math::static_size<
		N
	>
	storage_size;

	typedef
	value_type *
	pointer;

	typedef
	value_type &
	reference;

	typedef
	value_type const &
	const_reference;

	explicit
	view_storage(
		pointer const _data
	)
	:
		data_(
			_data
		)
	{
	}

	reference
	operator[](
		size_type const _index
	)
	{
		return
			data_[
				_index
			];
	}

	const_reference
	operator[](
		size_type const _index
	) const
	{
		return
			data_[
				_index
			];
	}
private:
	pointer data_;
};

}

TEST_CASE(
	"math::vector view storage",
	"[math],[vector]"
)
{
	typedef
	view_storage<
		unsigned,
		2
	>
	unsigned_view_storage;

	typedef
	fcppt::math::vector::object<
		unsigned,
		2,
		unsigned_view_storage
	>
	view_vector;

	std::array<
		unsigned,
		2u
	> array{{
		1,
		2
	}};

	view_vector const view{
		unsigned_view_storage(
			array.data()
		)
	};

	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	uivector2;

	uivector2 const vec(
		view
	);

	CHECK(
		vec
		==
		view
	);
}
