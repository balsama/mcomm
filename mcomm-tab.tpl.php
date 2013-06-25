<?php
$classes = array();
if ('node/' . $lp_nid == $_GET['q']) {
  $classes[] = 'active-trail';
}
$classes = implode(' ', $classes);
?>

<ul>
  <li class="<?php print $classes; ?>">
    <?php print l('Summer Guide', 'node/' . $lp_nid); ?>
  </li>
</ul>
