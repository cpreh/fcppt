//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/nonassignable.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/math/difference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/object.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <cstring>
#include <iterator>
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
		data_(
			_data
		)
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

		return result;
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

		return *this;
	}
private:
	pointer const data_;
};

template<
	typename Type,
	typename Pointer
>
class raw_iterator;

template<
	typename Type,
	typename Pointer
>
struct raw_iterator_base
{
	typedef boost::iterator_facade<
		raw_iterator<
			Type,
			Pointer
		>,
		Type,
		std::random_access_iterator_tag,
		proxy<
			Type,
			Pointer
		>,
		fcppt::math::difference_type
	> type;

};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type,
	typename Pointer
>
class raw_iterator
:
	public
		raw_iterator_base<
			Type,
			Pointer
		>::type
{
	typedef typename raw_iterator_base<
		Type,
		Pointer
	>::type base;
public:
	typedef typename base::value_type value_type;

	typedef typename base::reference reference;

	typedef Pointer pointer;

	typedef typename base::difference_type difference_type;

	typedef typename base::iterator_category iterator_category;

	explicit
	raw_iterator(
		pointer const _data
	)
	:
		data_(
			_data
		)
	{
	}

	template<
		typename OtherPointer
	>
	raw_iterator(
		raw_iterator<
			Type,
			OtherPointer
		> const &_other
	)
	:
		data_(
			_other.data_
		)
	{
	}
private:
	static
	difference_type
	stride()
	{
		return
			fcppt::cast::size<
				difference_type
			>(
				fcppt::cast::to_signed(
					sizeof(
						Type
					)
				)
			);
	}

	void
	advance(
		difference_type const _diff
	)
	{
		data_ +=
			this->stride()
			*
			_diff;
	}

	void
	increment()
	{
		data_ +=
			this->stride();
	}

	void
	decrement()
	{
		data_ -=
			this->stride();
	}

	bool
	equal(
		raw_iterator const &_other
	) const
	{
		return
			data_
			==
			_other.data_;
	}

	reference
	dereference() const
	{
		return
			reference(
				data_
			);
	}

	difference_type
	distance_to(
		raw_iterator const &_other
	) const
	{
		return
			(
				_other.data_
				-
				data_
			)
			/
			this->stride();
	}

	template<
		typename OtherType,
		typename OtherPointer
	>
	friend class raw_iterator;

	friend class boost::iterator_core_access;

	pointer data_;
};

FCPPT_PP_POP_WARNING

template<
	typename Type
>
class raw_view
{
public:
	typedef fcppt::math::size_type size_type;

	typedef unsigned char *pointer;

	typedef unsigned char const *const_pointer;

	typedef proxy<
		Type,
		pointer
	> reference;

	typedef proxy<
		Type,
		const_pointer
	> const_reference;

	typedef raw_iterator<
		Type,
		pointer
	> iterator;

	typedef raw_iterator<
		Type,
		const_pointer
	> const_iterator;

	raw_view(
		pointer const _data,
		size_type const _size
	)
	:
		data_(
			_data
		),
		size_(
			_size
		)
	{
	}

	pointer
	data()
	{
		return
			data_;
	}

	iterator
	begin()
	{
		return
			iterator(
				data_
			);
	}

	const_iterator
	begin() const
	{
		return
			const_iterator(
				data_
			);
	}

	size_type
	size() const
	{
		return
			size_;
	}
private:
	pointer data_;

	size_type size_;
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_vector_raw_view
)
{
FCPPT_PP_POP_WARNING

	typedef unsigned value_type;

	typedef raw_view<
		value_type
	> value_raw_view;

	fcppt::math::size_type const num_elements(
		2
	);

	typedef fcppt::math::vector::object<
		value_type,
		num_elements,
		value_raw_view
	> vector_raw;

	typedef std::array<
		unsigned char,
		sizeof(value_type) * num_elements
	> array_type;

	array_type array = {{ 0, 0 }};

	vector_raw vec(
		value_raw_view(
			array.data(),
			num_elements
		)
	);

	BOOST_CHECK_EQUAL(
		vector_raw::static_size::value,
		2u
	);

	vec[0] = 1u;

	vec[1] = 2u;

	BOOST_CHECK_EQUAL(
		vec[0],
		1u
	);

	BOOST_CHECK_EQUAL(
		vec[1],
		2u
	);

	vector_raw const copy(
		vec
	);

	BOOST_CHECK_EQUAL(
		copy[0],
		1u
	);

	BOOST_CHECK_EQUAL(
		copy[1],
		2u
	);
}
