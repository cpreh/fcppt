//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/size.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/object.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


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

	typedef value_type const *const_pointer;

	typedef value_type &reference;

	typedef value_type const &const_reference;

	typedef pointer iterator;

	typedef const_pointer const_iterator;

	view_storage(
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

	iterator
	begin()
	{
		return
			data_;
	}

	const_iterator
	begin() const
	{
		return
			data_;
	}

	iterator
	end()
	{
		return
			data_
			+
			size_;
	}

	const_iterator
	end() const
	{
		return
			data_
			+
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
	math_vector_view_storage
)
{
FCPPT_PP_POP_WARNING

	typedef view_storage<
		unsigned
	> unsigned_view_storage;

	typedef fcppt::math::vector::object<
		unsigned,
		fcppt::math::static_size<
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
			fcppt::cast::size<
				unsigned_view_storage::size_type
			>(
				sizeof(data) / sizeof(unsigned)
			)
		)
	);

	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	uivector2;

	uivector2 const vec(
		view
	);

	BOOST_CHECK_EQUAL(
		vec,
		view
	);
}
