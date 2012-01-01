//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_INCLUSIVE_RANGE_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_INCLUSIVE_RANGE_DECL_HPP_INCLUDED

#include <fcppt/random/inclusive_range_fwd.hpp>
#include <fcppt/random/range_decl.hpp>

namespace fcppt
{
namespace random
{

/// An inclusive range
template<
	typename T
>
class inclusive_range
:
	public range<
		T
	>
{
public:
	explicit inclusive_range(
		T const &first,
		T const &last
	);
};

}
}

#endif
