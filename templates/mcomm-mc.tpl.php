<div class="mandatory-articles">
  <?php print l('<h2 class="headline">Healthy You</h2>', 'node/' . $lp_nid, array('html' => TRUE)); ?>

  <p class="style-no-4368">Important information about your rights and benefits</p>

  <div class="mcomm-article-list mcomm-article-list-article clearfix">
    <?php
    $count = count($commset['mandatory_articles']);
    for ($i=0;$i<$count;$i++) {
      $zebra = ($i % 2) ? 'even' : 'odd';
      if ($zebra == 'odd') {
        if ($i == 4) {
          print '<div class="expandable">';
        }
        print '<div class="row clearfix">';
      }
      print l(lms_nid_to_title($commset['mandatory_articles'][$i]), 'node/' . $commset['mandatory_articles'][$i], array('attributes' => array('class' => $zebra)));
      if (($zebra == 'even') || (($i+1)==$count)) {
        print '</div>';
        if ((($i+1)==$count) && ($i >= 4)) {
          print '</div> <!-- END HIDDEN -->';
        }
      }
    }
    ?>
  </div>
  <div class="footer">
    <p class="mcomm-toggle" rel="collapsed">
      <span>+</span> Expand
    </p>
  </div>
</div>
