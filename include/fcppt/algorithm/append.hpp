//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_APPEND_HPP_INCLUDED
#define FCPPT_ALGORITHM_APPEND_HPP_INCLUDED

namespace fcppt
{
namespace algorithm
{

/**
 * \brief Appends the sequence @a src to @a dest.
 * \ingroup fcpptalgorithm
 * \tparam DestContainer Must have an insert function taking three integers (like the std containers all do).
 * \tparam SourceContainer Must have a <code>begin</code> and <code>end</code> member function.
 *
 * Example:
 *
 * \code
 * std::vector<int> v;
 * v.push_back(1);
 * v.push_back(2);
 * v.push_back(3);
 * std::vector<int> w;
 * w.push_back(4);
 * w.push_back(5);
 *
 * fcppt::algorithm::append(
 * 	v,
 * 	w);
 *
 * // Now v contains: 1,2,3,4,5
 * \endcode
 **/
template<
	typename DestContainer,
	typename SourceContainer
>
void
append(
	DestContainer &dest,
	SourceContainer const &src
)
{
	dest.insert(
		dest.end(),
		src.begin(),
		src.end()
	);
}

}
}

#endif
