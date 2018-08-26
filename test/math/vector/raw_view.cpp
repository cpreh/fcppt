//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/nonassignable.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/object.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <catch2/catch.hpp>
#include <cstring>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename Type,
	typename Pointer
>
class proxy
{
	FCPPT_NONASSIGNABLE(
		proxy
	);
public:
	typedef Pointer pointer;

	explicit
	proxy(
		pointer const _data
	)
	:
		data_{
			_data
		}
	{
	}

	operator Type() const
	{
		Type result;

		std::memcpy(
			&result,
			data_,
			sizeof(
				Type
			)
		);

		return
			result;
	}

	proxy &
	operator=(
		Type const &_other
	)
	{
		std::memcpy(
			data_,
			&_other,
			sizeof(
				Type
			)
		);

		return
			*this;
	}
private:
	pointer const data_;
};

template<
	typename Type
>
class raw_view
{
public:
	typedef
	fcppt::math::size_type
	size_type;

	typedef
	unsigned char *
	pointer;

	typedef
	unsigned char const *
	const_pointer;

	typedef
	proxy<
		Type,
		pointer
	>
	reference;

	typedef
	proxy<
		Type,
		const_pointer
	>
	const_reference;

	explicit
	raw_view(
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
			reference{
				this->index_of(
					_index
				)
			};
	}

	const_reference
	operator[](
		size_type const _index
	) const
	{
		return
			const_reference{
				this->index_of(
					_index
				)
			};
	}
private:
	pointer
	index_of(
		size_type const _index
	) const
	{
		return
			data_
			+
			fcppt::cast::to_signed(
				_index
				*
				sizeof(
					Type
				)
			);
	}

	pointer data_;
};

}

TEST_CASE(
	"math::vector raw_view",
	"[math],[vector]"
)
{
	typedef
	unsigned
	value_type;

	typedef
	raw_view<
		value_type
	>
	value_raw_view;

	constexpr fcppt::math::size_type const num_elements(
		2
	);

	typedef
	fcppt::math::vector::object<
		value_type,
		num_elements,
		value_raw_view
	>
	vector_raw;

	typedef
	std::array<
		unsigned char,
		sizeof(value_type)
		*
		num_elements
	>
	array_type;

	array_type array = {{ 0, 0 }};

	vector_raw vec(
		value_raw_view(
			array.data()
		)
	);

	static_assert(
		vector_raw::static_size::value
		==
		2u,
		""
	);

	vec.x() = 1u;

	vec.y() = 2u;

	CHECK(
		vec.x()
		==
		1u
	);

	CHECK(
		vec.y()
		==
		2u
	);

	vector_raw const copy(
		vec
	);

	CHECK(
		copy.x()
		==
		1u
	);

	CHECK(
		copy.y()
		==
		2u
	);
}
