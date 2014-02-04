<?php
/**
 * Configuration Form for Admin to set the secret and publishable keys.
 *
 * @return array
 *   Array of form values to be saved.
 */
function ebookbraintree_admin_settings() {
  $form = array(
    '#type' => 'fieldset',
    '#title' => t('My Module Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['ebookbraintree_readme'] = array(
    '#type' => 'markup',
    '#title' => t('Read me instructions'),
    '#markup' => '<p>' . l(t('Read me instructions'), 'admin/config/services/ebookbraintree/readme') . '</p>',
  );

  $form['ebookbraintree_ebook'] = array(
  '#type' => 'markup',
  '#title' => t('E-Book Generator'),
  '#markup' => '<p>' . l(t('Create an E-Book'), 'admin/config/services/ebookbraintree/create') . '</p>',
  );
  
  $form['ebookbraintree_reports'] = array(
    '#type' => 'markup',
    '#title' => t('Sales report'),
    '#markup' => '<p>' . l(t('See customer list'), 'admin/config/services/ebookbraintree/reports') . '</p>',
  );
  
  $form['ebookbraintree_warning'] = array(
    '#type' => 'markup',
    '#title' => t('What happens when my customer --buys now--?'),
    '#markup' => '<p> This module does not save ANYTHING about the credit cards or payment to this website.  The user may type it into the form on this website which gets sent immediately only to Braintree encrypted and you will only get a pass/fail message back.  Do not save anything about the payment for re-occuring billing, record keeping, or anything like that to this site.  You may view any details about each transaction at your Braintree account page. <br>&nbsp;<br>This module requires Javascript to be enabled for your site through out the process to work properly.  Your customers cannot buy products through your website using this module if they have disabled Javascript in their browser. </p>',
  );
  
  $form['ebookbraintree_whatits'] = array(
    '#type' => 'markup',
    '#title' => t('What is this module?'),
    '#markup' => '<p> This module will generate the necessary pages and asset holders for you to sell a pay-per-chapter e-book easily on this site. Visitors can come and view an introduction of your chapter along with the images and a BUY NOW button. If they push the button, enter in their credit card details, and submit, they can then view the entire chapter.  Drupal Commerce is recommended, but if that suite is too large for your needs, this is a simple payment solution.</p>',
  );
  
    $form['ebookbraintree_wherefrom'] = array(
    '#type' => 'markup',
    '#title' => t('Where to get the TEST information for this page from?'),
    '#markup' => '<p>' . l(t('Sign up for a Braintree Payments test account:'), 'https://www.braintreepayments.com/get-started') . '</p>',
  );
  
  $form['ebookbraintree_wherefrom2'] = array(
    '#type' => 'markup',
    '#title' => t('Where to get the LIVE information for this page from?'),
    '#markup' => '<p>' . l(t('Sign up for a Braintree Payments live account:'), 'https://braintreepayments.com') . '</p>',
  );
  
  $form['ebookbraintree_environment'] = array(
    '#type' => 'textfield',
    '#title' => t('Braintree environment setting'),
    '#default_value' => variable_get('ebookbraintree_environment', ""),
    '#description' => t('Braintree environment setting'),
    '#required' => TRUE,
  );

  $form['ebookbraintree_merchantId_testkey'] = array(
    '#type' => 'textfield',
    '#title' => t('Braintree Test Merchant Id'),
    '#default_value' => variable_get('ebookbraintree_merchantId_testkey', ""),
    '#description' => t('Braintree Test Merchant Id'),
    '#required' => TRUE,
  );

  $form['ebookbraintree_merchantId_livekey'] = array(
    '#type' => 'textfield',
    '#title' => t('Braintree Live Merchant Id'),
    '#default_value' => variable_get('ebookbraintree_merchantId_livekey', ""),
    '#description' => t('Braintree Live Merchant Id'),
    '#required' => TRUE,
  );
  
  $form['ebookbraintree_publishable_testkey'] = array(
    '#type' => 'textfield',
    '#title' => t('Braintree test public API Key'),
    '#default_value' => variable_get('ebookbraintree_publishable_testkey', ""),
    '#description' => t('Braintree test public API Key'),
    '#required' => TRUE,
  );

  $form['ebookbraintree_publishable_livekey'] = array(
    '#type' => 'textfield',
    '#title' => t('Braintree live public API Key'),
    '#default_value' => variable_get('ebookbraintree_publishable_livekey', ""),
    '#description' => t('Braintree live public API Key'),
    '#required' => TRUE,
  );

  $form['ebookbraintree_secret_testkey'] = array(
    '#type' => 'textfield',
    '#title' => t('Braintree test secret API Key'),
    '#default_value' => variable_get('ebookbraintree_secret_testkey', ""),
    '#description' => t('Braintree test secret API Key'),
    '#required' => TRUE,
  );

  $form['ebookbraintree_secret_livekey'] = array(
    '#type' => 'textfield',
    '#title' => t('Braintree live secret API Key'),
    '#default_value' => variable_get('ebookbraintree_secret_livekey', ""),
    '#description' => t('Braintree live secret API Key'),
    '#required' => TRUE,
  );

  $form['ebookbraintree_price'] = array(
    '#type' => 'textfield',
    '#title' => t('Price in USA dollars of download'),
    '#default_value' => variable_get('ebookbraintree_price', ""),
    '#description' => t('Price in USA dollars of download'),
    '#required' => TRUE,
  );
  
  $form['ebookbraintree_gonelive'] = array(
    '#type' => 'checkbox',
    '#title' => t('Live?'),
    '#default_value' => variable_get('ebookbraintree_gonelive', ""),
    '#description' => t('Check this box to use your live key.  Uncheck to enter demo mode and use your test key'),
  );
  
  $form['ebookbraintree_sslmessage'] = array(
    '#type' => 'checkbox',
    '#title' => t('SSL error message?'),
    '#default_value' => variable_get('ebookbraintree_sslmessage', ""),
    '#description' => t('This is not recommended, but you can get away with using this module on non-SSL/http servers.  To show an error message at the top of this page while you dont have an HTTPS secure connection, so that site admins know, check this box.'),
  );

  $form['ebookbraintree_sendemail'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send emails to admin and customer for each successful transaction?'),
    '#default_value' => variable_get('ebookbraintree_sendemail', ""),
    '#description' => t('Check this box to send emails.  Uncheck to not send emails.'),
  );
  

  $form['ebookbraintree_fields_description'] = array(
    '#type' => 'markup',
    '#title' => t('Which fields do you want to collect?'),
    '#markup' => '<hr /><p>You have the choice to collect the following information from your customers below</p>',
  );

  $form['ebookbraintree_firstname'] = array(
    '#type' => 'checkbox',
    '#title' => t('First Name?'),
    '#default_value' => variable_get('ebookbraintree_firstname', ""),
    '#description' => t('Check this box to collect first names.  Uncheck to leave the first name box off of the checkout form.'),
  );
  
  $form['ebookbraintree_lastname'] = array(
    '#type' => 'checkbox',
    '#title' => t('Last Name?'),
    '#default_value' => variable_get('ebookbraintree_lastname', ""),
    '#description' => t('Check this box to collect last names.  Uncheck to leave the last name box off of the checkout form.'),
  );
  
  $form['ebookbraintree_phone'] = array(
    '#type' => 'checkbox',
    '#title' => t('Phone Number?'),
    '#default_value' => variable_get('ebookbraintree_phone', ""),
    '#description' => t('Check this box to collect phone numbers.  Uncheck to leave the phone number box off of the checkout form.'),
  );
  
  $form['ebookbraintree_address'] = array(
    '#type' => 'checkbox',
    '#title' => t('Address 1?'),
    '#default_value' => variable_get('ebookbraintree_address', ""),
    '#description' => t('Check this box to collect address 1.  Uncheck to leave the address 1 box off of the checkout form.'),
  );
  
  $form['ebookbraintree_address2'] = array(
    '#type' => 'checkbox',
    '#title' => t('Address 2?'),
    '#default_value' => variable_get('ebookbraintree_address2', ""),
    '#description' => t('Check this box to collect address 2.  Uncheck to leave the address 2 box off of the checkout form.'),
  );
  
  $form['ebookbraintree_city'] = array(
    '#type' => 'checkbox',
    '#title' => t('City?'),
    '#default_value' => variable_get('ebookbraintree_city', ""),
    '#description' => t('Check this box to collect city.  Uncheck to leave the city box off of the checkout form.'),
  );
  
  $form['ebookbraintree_county'] = array(
    '#type' => 'checkbox',
    '#title' => t('County?'),
    '#default_value' => variable_get('ebookbraintree_county', ""),
    '#description' => t('Check this box to collect county.  Uncheck to leave the county box off of the checkout form.'),
  );
  
  $form['ebookbraintree_state'] = array(
    '#type' => 'checkbox',
    '#title' => t('State?'),
    '#default_value' => variable_get('ebookbraintree_state', ""),
    '#description' => t('Check this box to collect state.  Uncheck to leave the state box off of the checkout form.'),
  );
  
  $form['ebookbraintree_zip'] = array(
    '#type' => 'checkbox',
    '#title' => t('Zip?'),
    '#default_value' => variable_get('ebookbraintree_zip', ""),
    '#description' => t('Check this box to collect zip codes.  Uncheck to leave the zip code box off of the checkout form.'),
  );
  return system_settings_form($form);
}