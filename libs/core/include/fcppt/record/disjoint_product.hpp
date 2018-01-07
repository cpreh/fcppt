//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DISJOINT_PRODUCT_HPP_INCLUDED
#define FCPPT_RECORD_DISJOINT_PRODUCT_HPP_INCLUDED

#include <fcppt/record/detail/disjoint_product.hpp>


namespace fcppt
{
namespace record
{

/**
\brief The product of two disjoint records

\ingroup fcpptrecord
*/
template<
	typename RecordL,
	typename RecordR
>
using
disjoint_product
=
typename
fcppt::record::detail::disjoint_product<
	RecordL,
	RecordR
>::type;

}
}

#endif
