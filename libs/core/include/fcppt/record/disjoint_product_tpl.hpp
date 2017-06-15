//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DISJOINT_PRODUCT_TPL_HPP_INCLUDED
#define FCPPT_RECORD_DISJOINT_PRODUCT_TPL_HPP_INCLUDED

#include <fcppt/mpl/append.hpp>
#include <fcppt/record/are_disjoint.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/object_impl.hpp>


namespace fcppt
{
namespace record
{

/**
\brief The product of two disjoint records
*/
template<
	typename RecordL,
	typename RecordR
>
struct disjoint_product_tpl
{
	static_assert(
		fcppt::record::are_disjoint<
			RecordL,
			RecordR
		>::value,
		"RecordL and RecordR must be disjoint"
	);

	typedef
	fcppt::record::object<
		typename
		fcppt::mpl::append<
			fcppt::record::element_vector<
				RecordL
			>,
			fcppt::record::element_vector<
				RecordR
			>
		>::type
	>
	type;
};

}
}

#endif
