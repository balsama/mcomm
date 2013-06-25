<?php
function mcomm_admin() {
  $description = '<p>Communication Sets (CommSets) are initially defined in the `commsets.inc` file and are loaded into the database using the "Update Definitions" below. The definitions in the database are the ones used by the site. Use the "Show Definitions" button to compare the two (Devel module must be enabled).</p>';
  return $description . drupal_get_form('mcomm_define_form') . drupal_get_form('mcomm_update_form') . drupal_get_form('mcomm_lp_nid');
}

/**
 * Show definitions form.
 */
function mcomm_define_form() {
  $form['show'] = array(
    '#type' => 'fieldset',
    '#title' => 'Show Definitions',
    '#collapsible' => FALSE,
  );

  $form['show']['mcomm_define_form_desc'] = array(
    '#value' => '<p>Click "Show Definitions" to display the CommSets as defined in the `commset.inc` file and as they are currently defined in the database.</p>',
  );

  $form['show']['mcomm_define_form_show'] = array(
    '#type' => 'submit',
    '#value' => 'Show Definitions',
  );

  // If Devel is not enabled disable the button.
  if (!function_exists('dpm')) {
    $form['show']['mcomm_form_show']['#disabled'] = TRUE;
    $form['show']['mcomm_form_show']['#suffix'] = '<em>This button is disabled because the module Devel is not enabled.</em>';
  }

  return $form;
}
function mcomm_define_form_submit($form, &$form_state) {
  dpm(mcomm_get_file_commset_definitions(), 'File Definitions');
  dpm(mcomm_get_db_commset_definitions(), 'Database Definitions (Loaded Configuration)');
}

/**
 * Update definitions form.
 */
function mcomm_update_form() {
  $form['update'] = array(
    '#type' => 'fieldset',
    '#title' => 'Update Definitions',
    '#collapsible' => FALSE,
  );

  $form['update']['mcomm_update_form_desc'] = array(
    '#value' => '<p>Click "Update Definitions" to overwrite the loaded database CommSet definitions with the definitions in the `commset.inc` file.</p>',
  );

   $form['update']['mcomm_define_update_show'] = array(
    '#type' => 'submit',
    '#value' => 'Update Definitions',
  );

  return $form;
}
function mcomm_update_form_submit($form, &$form_submit) {
  mcomm_update_commset_definitions();
}

/**
 * Landing Page Node ID Form
 */
function mcomm_lp_nid() {
  $form['mcomm_lp_nid'] = array(
    '#type' => 'textfield',
    '#title' => 'Landing Page Node ID',
    '#description' => 'Enter the Node ID of the main landing page. This might vary between environments.',
    '#default_value' => variable_get('mcomm_lp_nid', 'Please Enter'),
    '#size' => 5,
    '#maxlength' => 5,
  );
  return system_settings_form($form);
}
