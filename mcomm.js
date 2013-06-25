$(document).ready(function() {
  $('.mcomm-toggle').click(function() {
    var state = $(this).attr('rel');
    toggle_mcomm(state);
  });
});

function toggle_mcomm(state) {
  if (state == 'collapsed') {
    mcomm_open();
  }
  else if (state == 'expanded') {
    mcomm_close();
  }
}

function mcomm_open() {
  $('.mcomm-toggle').attr('rel', 'expanded');
  $('.mcomm-article-list-article .expandable').slideDown();
  $('.mcomm-toggle').html('<span>-</span> Collapse');
}

function mcomm_close() {
  $('.mcomm-toggle').attr('rel', 'collapsed');
  $('.mcomm-article-list-article .expandable').slideUp();
  $('.mcomm-toggle').html('<span>+</span> Expand');
}
