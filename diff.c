#include "parse-options.h"
static unsigned parse_color_moved_ws(const char *arg)
		if (!strcmp(sb.buf, "no"))
			ret = 0;
		else if (!strcmp(sb.buf, "ignore-space-change"))
		else {
			ret |= COLOR_MOVED_WS_ERROR;
			error(_("unknown color-moved-ws mode '%s', possible values are 'ignore-space-change', 'ignore-space-at-eol', 'ignore-all-space', 'allow-indentation-change'"), sb.buf);
		}
	    (ret & XDF_WHITESPACE_FLAGS)) {
		error(_("color-moved-ws: allow-indentation-change cannot be combined with other whitespace modes"));
		ret |= COLOR_MOVED_WS_ERROR;
	}
		unsigned cm = parse_color_moved_ws(value);
		if (cm & COLOR_MOVED_WS_ERROR)
	external_diff_cmd = xstrdup_or_null(getenv("GIT_EXTERNAL_DIFF"));
	int indent_off;   /* Offset to first non-whitespace character */
	int indent_width; /* The visual width of the indentation */
	int wsd; /* The whitespace delta of this block */
	memset(b, 0, sizeof(*b));
#define INDENT_BLANKLINE INT_MIN

static void fill_es_indent_data(struct emitted_diff_symbol *es)
	unsigned int off = 0, i;
	int width = 0, tab_width = es->flags & WS_TAB_WIDTH_MASK;
	const char *s = es->line;
	const int len = es->len;

	/* skip any \v \f \r at start of indentation */
	while (s[off] == '\f' || s[off] == '\v' ||
	       (s[off] == '\r' && off < len - 1))
		off++;

	/* calculate the visual width of indentation */
	while(1) {
		if (s[off] == ' ') {
			width++;
			off++;
		} else if (s[off] == '\t') {
			width += tab_width - (width % tab_width);
			while (s[++off] == '\t')
				width += tab_width;
		} else {
			break;
		}
	}

	/* check if this line is blank */
	for (i = off; i < len; i++)
		if (!isspace(s[i]))
		    break;

	if (i == len) {
		es->indent_width = INDENT_BLANKLINE;
		es->indent_off = len;
	} else {
		es->indent_off = off;
		es->indent_width = width;
	}
}

static int compute_ws_delta(const struct emitted_diff_symbol *a,
			    const struct emitted_diff_symbol *b,
			    int *out)
{
	int a_len = a->len,
	    b_len = b->len,
	    a_off = a->indent_off,
	    a_width = a->indent_width,
	    b_off = b->indent_off,
	    b_width = b->indent_width;
	int delta;

	if (a_width == INDENT_BLANKLINE && b_width == INDENT_BLANKLINE) {
		*out = INDENT_BLANKLINE;
		return 1;
	}
	if (a->s == DIFF_SYMBOL_PLUS)
		delta = a_width - b_width;
	else
		delta = b_width - a_width;

	if (a_len - a_off != b_len - b_off ||
	    memcmp(a->line + a_off, b->line + b_off, a_len - a_off))
	*out = delta;
	int al = cur->es->len, bl = match->es->len, cl = l->len;
	int a_off = cur->es->indent_off,
	    a_width = cur->es->indent_width,
	    c_off = l->indent_off,
	    c_width = l->indent_width;
	int delta;
	 * We need to check if 'cur' is equal to 'match'.  As those
	 * are from the same (+/-) side, we do not need to adjust for
	 * indent changes. However these were found using fuzzy
	 * matching so we do have to check if they are equal. Here we
	 * just check the lengths. We delay calling memcmp() to check
	 * the contents until later as if the length comparison for a
	 * and c fails we can avoid the call all together.
	if (al != bl)
	/* If 'l' and 'cur' are both blank then they match. */
	if (a_width == INDENT_BLANKLINE && c_width == INDENT_BLANKLINE)
		return 0;
	 * The indent changes of the block are known and stored in pmb->wsd;
	 * however we need to check if the indent changes of the current line
	 * match those of the current block and that the text of 'l' and 'cur'
	 * after the indentation match.
	if (cur->es->s == DIFF_SYMBOL_PLUS)
		delta = a_width - c_width;
	else
		delta = c_width - a_width;
	/*
	 * If the previous lines of this block were all blank then set its
	 * whitespace delta.
	 */
	if (pmb->wsd == INDENT_BLANKLINE)
		pmb->wsd = delta;
	return !(delta == pmb->wsd && al - a_off == cl - c_off &&
		 !memcmp(a, b, al) && !
		 memcmp(a + a_off, c + c_off, al - a_off));
		if (o->color_moved_ws_handling &
		    COLOR_MOVED_WS_ALLOW_INDENTATION_CHANGE)
			fill_es_indent_data(&o->emitted_symbols->buf[n]);
			memset(&pmb[rp], 0, sizeof(pmb[rp]));
 * Returns 0 if the last block is empty or is unset by this function, non zero
 * otherwise.
 *
static int adjust_last_block(struct diff_options *o, int n, int block_length)
		return block_length;
				return 1;
	return 0;
	int n, flipped_block = 0, block_length = 0;
		enum diff_symbol last_symbol = 0;
			flipped_block = 0;
			flipped_block = 0;
			last_symbol = l->s;
		if (o->color_moved == COLOR_MOVED_PLAIN) {
			last_symbol = l->s;
			l->flags |= DIFF_SYMBOL_MOVED_LINE;
		}
					pmb[pmb_nr].wsd = 0;
			if (adjust_last_block(o, n, block_length) &&
			    pmb_nr && last_symbol != l->s)
				flipped_block = (flipped_block + 1) % 2;
			else
				flipped_block = 0;
		if (pmb_nr) {
			block_length++;
			l->flags |= DIFF_SYMBOL_MOVED_LINE;
			if (flipped_block && o->color_moved != COLOR_MOVED_BLOCKS)
				l->flags |= DIFF_SYMBOL_MOVED_LINE_ALT;
		}
		last_symbol = l->s;
	struct emitted_diff_symbol e = {line, len, flags, 0, 0, s};
static void emit_add_line(struct emit_callback *ecbdata,
static void emit_del_line(struct emit_callback *ecbdata,
static void emit_context_line(struct emit_callback *ecbdata,
static struct diff_tempfile *claim_diff_tempfile(void)
{
			emit_del_line(ecb, data, len);
			emit_add_line(ecb, data, len);
static unsigned long sane_truncate_line(char *line, unsigned long len)
		len = sane_truncate_line(line, len);
		emit_add_line(ecbdata, line + 1, len - 1);
		emit_del_line(ecbdata, line + 1, len - 1);
		emit_context_line(ecbdata, line + 1, len - 1);
		char *s = xstrfmt("%"PRIuMAX , (uintmax_t)orig_size);
struct userdiff_driver *get_textconv(struct repository *r,
	diff_filespec_load_driver(one, r->index);
	return userdiff_get_textconv(r, one->driver);
		textconv_one = get_textconv(o->repo, one);
		textconv_two = get_textconv(o->repo, two);
		const char *diffopts;

		diffopts = getenv("GIT_DIFF_OPTS");

		run_external_diff(pgm, name, other, one, two, xfrm_msg, o);
static void prep_parse_options(struct diff_options *options);


	prep_parse_options(options);

	FREE_AND_NULL(options->parseopts);
static void enable_patch_output(int *fmt)
{
static int diff_opt_unified(const struct option *opt,
			    const char *arg, int unset)
{
	struct diff_options *options = opt->value;
	char *s;

	BUG_ON_OPT_NEG(unset);

	options->context = strtol(arg, &s, 10);
	if (*s)
		return error(_("%s expects a numerical value"), "--unified");
	enable_patch_output(&options->output_format);

	return 0;
}

static void prep_parse_options(struct diff_options *options)
{
	struct option parseopts[] = {
		OPT_GROUP(N_("Diff output format options")),
		OPT_BITOP('p', "patch", &options->output_format,
			  N_("generate patch"),
			  DIFF_FORMAT_PATCH, DIFF_FORMAT_NO_OUTPUT),
		OPT_BITOP('u', NULL, &options->output_format,
			  N_("generate patch"),
			  DIFF_FORMAT_PATCH, DIFF_FORMAT_NO_OUTPUT),
		OPT_CALLBACK_F('U', "unified", options, N_("<n>"),
			       N_("generate diffs with <n> lines context"),
			       PARSE_OPT_NONEG, diff_opt_unified),
		OPT_BOOL('W', "function-context", &options->flags.funccontext,
			 N_("generate diffs with <n> lines context")),
		OPT_BIT_F(0, "raw", &options->output_format,
			  N_("generate the diff in raw format"),
			  DIFF_FORMAT_RAW, PARSE_OPT_NONEG),
		OPT_END()
	};

	ALLOC_ARRAY(options->parseopts, ARRAY_SIZE(parseopts));
	memcpy(options->parseopts, parseopts, sizeof(parseopts));
}

	ac = parse_options(ac, av, prefix, options->parseopts, NULL,
			   PARSE_OPT_KEEP_DASHDASH |
			   PARSE_OPT_KEEP_UNKNOWN |
			   PARSE_OPT_NO_INTERNAL_HELP |
			   PARSE_OPT_ONE_SHOT |
			   PARSE_OPT_STOP_AT_NON_OPTION);

	if (ac)
		return ac;

	if (!strcmp(arg, "--patch-with-raw")) {
			return error("bad --color-moved argument: %s", arg);
	} else if (!strcmp(arg, "--no-color-moved-ws")) {
		options->color_moved_ws_handling = 0;
		unsigned cm = parse_color_moved_ws(arg);
		if (cm & COLOR_MOVED_WS_ERROR)
			return -1;
		options->color_moved_ws_handling = cm;
		esm.nr = 0;

		o->emitted_symbols = NULL;
void diffcore_fix_diff_index(void)
	textconv = get_textconv(r, df);