//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_signed.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/object.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <array>
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
public:
	using
	pointer
	=
	Pointer;

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

	proxy(
		proxy const &
	)
	= default;

	proxy(
		proxy &&
	)
	noexcept
	= default;

	proxy &
	operator=(
		proxy const &
	)
	= default;

	proxy &
	operator=(
		proxy &&
	)
	noexcept
	= default;

	~proxy()
	= default;

	// NOLINTNEXTLINE(google-explicit-constructor,hicpp-explicit-conversions)
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
	pointer data_;
};

template<
	typename Type
>
class raw_view
{
public:
	using
	size_type
	=
	fcppt::math::size_type;

	using
	pointer
	=
	unsigned char *;

	using
	const_pointer
	=
	unsigned char const *;

	using
	reference
	=
	proxy<
		Type,
		pointer
	>;

	using
	const_reference
	=
	proxy<
		Type,
		const_pointer
	>;

	explicit
	raw_view(
		pointer const _data // NOLINT(misc-misplaced-const)
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
	[[nodiscard]]
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
	using
	value_type
	=
	unsigned;

	using
	value_raw_view
	=
	raw_view<
		value_type
	>;

	constexpr fcppt::math::size_type const num_elements(
		2U
	);

	using
	vector_raw
	=
	fcppt::math::vector::object<
		value_type,
		num_elements,
		value_raw_view
	>;

	using
	array_type
	=
	std::array<
		unsigned char,
		sizeof(value_type)
		*
		num_elements
	>;

	array_type array = {{ 0, 0 }};

	vector_raw vec(
		value_raw_view(
			array.data()
		)
	);

	static_assert(
		vector_raw::static_size::value
		==
		2U
	);

	vec.x() = 1U;

	vec.y() = 2U;

	CHECK(
		vec.x()
		==
		1U
	);

	CHECK(
		vec.y()
		==
		2U
	);

	vector_raw const copy(
		vec
	);

	CHECK(
		copy.x()
		==
		1U
	);

	CHECK(
		copy.y()
		==
		2U
	);
}
