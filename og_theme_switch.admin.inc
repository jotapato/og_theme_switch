<?php

/**
 * @file
 * og_theme_switch administration functions.
 */

/**
 * Form for theme settings.
 */
function og_theme_switch_admin_settings() {
  $options = og_theme_switch_options();
  $spaces = og_theme_switch_spaces();
  
  if(empty($options)){
    drupal_set_message(t('You should activate more than one theme.'),'warning');
    return FALSE;
  }
  if(empty($spaces)){
    drupal_set_message(t('You should activate more than one group.'),'warning');
    return FALSE;
  }
  
  foreach ($spaces as $s => $space) {
    $form['og_theme_switch']['og_theme_switch_space_'. $s] = array(
      '#type' => 'fieldset',
      '#title' => $space,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['og_theme_switch']['og_theme_switch_space_'. $s]['space_'. $s] = array(
      '#type' => 'hidden',
      '#title' => $space,
      '#default_value' => variable_get('space_'. $space, $s),
      '#disabled' => TRUE,
    );
    $form['og_theme_switch']['og_theme_switch_space_'. $s]['og_theme_switch_'. $s] = array(
      '#type' => 'checkboxes',
      '#title' => t('Themes'),
      '#default_value' => variable_get('og_theme_switch_'. $s, $options),
      '#options' => $options,
    );
  }
  return system_settings_form($form);
}
