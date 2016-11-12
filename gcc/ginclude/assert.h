#ifdef _GCC_ASSERT_H
# undef _GCC_ASSERT_H
# undef assert
#endif

#define _GCC_ASSERT_H 1

#if !defined NDEBUG && defined __OPTIMIZE__ && defined __ASSUME_ASSERTS__
# define assert(cond) ((__builtin_has_side_effects_p((cond)) || (cond)) ? (void)0 : __builtin_unreachable())
#else
# include_next <assert.h>
#endif
