//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/element_to_type_tpl.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/map_elements.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename Function,
	typename Param
>
struct result_helper
{
	typedef
	typename
	std::result_of<
		Function(
			fcppt::record::element_to_type<
				Param
			>
		)
	>::type
	type;
};

}

int
main()
{
	FCPPT_RECORD_MAKE_LABEL(
		int_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		bool_label
	);

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			int_label,
			int
		>,
		fcppt::record::element<
			bool_label,
			bool
		>
	>
	my_record;

	typedef
	fcppt::record::map_elements<
		my_record,
		fcppt::optional::object<
			fcppt::record::element_to_type_tpl<
				boost::mpl::_
			>
		>
	>
	result;

	auto const transform(
		[](
			auto const &_value
		)
		{
			return
				fcppt::optional::make(
					_value
				);
		}
	);

	typedef
	fcppt::record::map_elements<
		my_record,
		result_helper<
			decltype(
				transform
			),
			boost::mpl::_
		>
	>
	result2;

	static_assert(
		std::is_same<
			fcppt::record::label_value_type<
				result,
				int_label
			>,
			fcppt::optional::object<
				int
			>
		>::value,
		""
	);

	static_assert(
		std::is_same<
			fcppt::record::label_value_type<
				result,
				bool_label
			>,
			fcppt::optional::object<
				bool
			>
		>::value,
		""
	);

	static_assert(
		std::is_same<
			result,
			result2
		>::value,
		""
	);
}
