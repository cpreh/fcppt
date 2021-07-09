//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LAMBDA_CONCEPT_HPP_INCLUDED
#define FCPPT_MPL_LAMBDA_CONCEPT_HPP_INCLUDED

#include <fcppt/mpl/is_lambda.hpp>

namespace fcppt::mpl
{

/**
\brief Concept for lambdas.
\ingroup fcpptmpl
\see fcppt::mpl::is_lambda
*/
template<typename T>
concept lambda_concept = fcppt::mpl::is_lambda<T>::value;

}

#endif
