//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FUNCTION_OBJECT_FWD_HPP_INCLUDED
#define FCPPT_FUNCTION_OBJECT_FWD_HPP_INCLUDED

namespace fcppt
{

namespace function
{

/**
 * @brief a fully std tr1 compliant function object class
 *
 * This class was introduced beause the gcc implementation had problems
 * with boost::phoenix.
 * To encounter this, fcppt::function::object is a wrapper around std::tr1::function
 *
 */
template< typename Singature >
class object;

} // end namespace function

} // end namespace fcppt

#endif
