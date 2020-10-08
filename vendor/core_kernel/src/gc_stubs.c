#define CAML_INTERNALS
#include <caml/memory.h>
#include <caml/gc_ctrl.h>

#ifdef _MSC_VER
#define PARAM_UNUSED
#else
#define PARAM_UNUSED __attribute__((unused))
#endif

static intnat minor_words(void)
{
  return (intnat) (caml_stat_minor_words +
            (double) (caml_young_end - caml_young_ptr));
}

static intnat promoted_words(void)
{
  return ((intnat) caml_stat_promoted_words);
}

CAMLprim value core_kernel_gc_minor_words(value unit PARAM_UNUSED)
{
  return Val_long(minor_words());
}

static intnat major_words(void)
{
  return (intnat) (caml_stat_major_words + (double) caml_allocated_words);
}

CAMLprim value core_kernel_gc_major_words(value unit PARAM_UNUSED)
{
  return Val_long(major_words());
}

CAMLprim value core_kernel_gc_promoted_words(value unit PARAM_UNUSED)
{
  return Val_long(promoted_words());
}

CAMLprim value core_kernel_gc_minor_collections(value unit PARAM_UNUSED)
{
  return Val_long(caml_stat_minor_collections);
}

CAMLprim value core_kernel_gc_major_collections(value unit PARAM_UNUSED)
{
  return Val_long(caml_stat_major_collections);
}

CAMLprim value core_kernel_gc_heap_words(value unit PARAM_UNUSED)
{
  return Val_long(caml_stat_heap_wsz);
}

CAMLprim value core_kernel_gc_heap_chunks(value unit PARAM_UNUSED)
{
  return Val_long(caml_stat_heap_chunks);
}

CAMLprim value core_kernel_gc_compactions(value unit PARAM_UNUSED)
{
  return Val_long(caml_stat_compactions);
}

CAMLprim value core_kernel_gc_top_heap_words(value unit PARAM_UNUSED)
{
  return Val_long(caml_stat_top_heap_wsz);
}

CAMLprim value core_kernel_gc_major_plus_minor_words(value unit PARAM_UNUSED)
{
  return Val_long(minor_words() + major_words());
}

CAMLprim value core_kernel_gc_allocated_words(value unit PARAM_UNUSED)
{
  return Val_long(minor_words() + major_words() - promoted_words());
}
