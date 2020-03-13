//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_SPLIT_STRING_HPP_INCLUDED
#define FCPPT_ALGORITHM_SPLIT_STRING_HPP_INCLUDED

#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Splits a string, using a delimiter.

\ingroup fcpptalgorithm

Let \f$ \mathrm{\_string} = (c_1, \dots , c_n)\f$, where \f$ n \ge 0 \f$
and \f$ p_1 < \dots < p_m \f$, where \f$ m \ge 0 \f$, be the positions of \a _string with value \a _delim.
Also, let \f$ p_{m+1} = \mathrm{\_string.size()}\f$.
The result is
\f[
 (\mathrm{\_string}[0,p_1-1], \mathrm{\_string}[p_1+1,p_2-1], \dots, \mathrm{\_string}[p_m+1,p_{m+1}-1).
\f]
Note that in case m is 0, the string itself is returned as a single element.

\tparam String Must be a container, constructible with a pair of iterators.
*/
template<
	typename String
>
std::vector<
	String
>
split_string(
	String const &_string,
	fcppt::type_traits::value_type<
		String
	> const _delim
)
{
	typedef
	typename
	String::const_iterator
	iterator;

	std::vector<
		String
	>
	result{};

	iterator cur{
		_string.begin()
	};

	iterator last{
		cur
	};

	for(
		;
		cur != _string.end();
		++cur
	)
	{
		if(
			*cur
			==
			_delim
		)
		{
			result.push_back(
				String{
					last,
					cur
				}
			);

			last =
				// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
				std::next(
					cur
				);
		}
	}

	result.push_back(
		String{
			last,
			cur
		}
	);

	return
		result;
}

}
}

#endif
