#ifndef FCPPT_ALGORITHM_COPY_IF_HPP_INCLUDED
#define FCPPT_ALGORITHM_COPY_IF_HPP_INCLUDED

namespace fcppt
{
namespace algorithm
{
/**
\brief Assigns the values of elements from a source range satisfying a predicate to a destination range,
\tparam InputIterator An input iterator type
\tparam OutputIterator An output iterator type
\tparam Predicate An unary predicate
\ingroup fcpptalgorithm
\param first An input iterator addressing the position of the first element in the source range.
\param last An input iterator addressing the position that is one past the final element in the source range.
\param result An output iterator addressing the position of the first element in the destination range.
\param pred User-defined predicate function object that defines the condition to be satisfied if an element is to be counted. A predicate takes single argument and returns <code>true</code> or <code>false</code>.
\return An iterator pointing to one past the last position where an element was inserted into the destination range

The C++03's standard library is missing this function. C++11 includes it in the
standard library, but for compatibility, you can use fcppt's version.
*/
template
<
	typename InputIterator,
	typename OutputIterator,
	typename Predicate
>
OutputIterator
copy_if(
	InputIterator first,
	InputIterator last,
	OutputIterator result,
	Predicate pred)
{
	while(first != last)
	{
		if(pred(*first))
			*result++ = *first;
		++first;
	}
	return result;
}

}
}

#endif
